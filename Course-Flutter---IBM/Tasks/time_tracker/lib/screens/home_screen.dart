import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../providers/expense_provider.dart';
import './add_entry_screen.dart';
import '../screens/category_management_screen.dart';
import '../screens/tag_management_screen.dart';
import 'package:intl/intl.dart';
import 'package:collection/collection.dart';
import '../models/expense.dart';
import '../models/expense_category.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen>
    with SingleTickerProviderStateMixin {
  late TabController _tabController;

  @override
  void initState() {
    super.initState();
    _tabController = TabController(length: 2, vsync: this);
  }

  @override
  void dispose() {
    _tabController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Time Tracking"),
        backgroundColor: const Color.fromARGB(255, 24, 173, 141),
        foregroundColor: Colors.white,
        bottom: TabBar(
          controller: _tabController,
          indicatorColor: const Color.fromARGB(255, 241, 204, 102),
          labelColor: Colors.white,
          unselectedLabelColor: Colors.white70,
          tabs: const [
            Tab(text: "All Entries"),
            Tab(text: "Grouped by Projects"),
          ],
        ),
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: <Widget>[
            const DrawerHeader(
              decoration: BoxDecoration(color: const Color.fromARGB(255, 24, 173, 141)),
              child: Text('Menu',
                  style: TextStyle(color: Colors.white, fontSize: 24)),
            ),
            ListTile(
              leading: const Icon(Icons.folder, color: Colors.black),
              title: const Text('Projects'),
              onTap: () {
                Navigator.pop(context); // This closes the drawer
                Navigator.pushNamed(context, '/manage_categories');
              },
            ),
            ListTile(
              leading: const Icon(Icons.task, color: Colors.black),
              title: const Text('Tasks'),
              onTap: () {
                Navigator.pop(context); // This closes the drawer
                Navigator.pushNamed(context, '/manage_tags');
              },
            ),
          ],
        ),
      ),
      body: TabBarView(
        controller: _tabController,
        children: [
          buildExpensesByDate(context),
          buildExpensesByCategory(context),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        backgroundColor: const Color.fromARGB(255, 241, 204, 102),
        onPressed: () => Navigator.push(context,
            MaterialPageRoute(builder: (context) => AddEntryScreen())),
        tooltip: 'Add Entries',
        child: const Icon(Icons.add, color: Colors.white), 
      ),
    );
  }

  Widget buildExpensesByDate(BuildContext context) {
    return Consumer<ExpenseProvider>(
      builder: (context, provider, child) {
        if (provider.expenses.isEmpty) {
          return const Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center, // Centra en eje Y
              mainAxisSize: MainAxisSize.max,
              children: <Widget>[
                Icon(Icons.lock_clock, size: 64, color: Colors.grey),
                Text("No time entries yet.",
                  style: TextStyle(
                    color: Color.fromARGB(255, 85, 85, 85), 
                    fontSize: 20)
                ),
                Text("Tap the + button to add your first entry.",
                  style: TextStyle(
                    color: Color.fromARGB(255, 141, 141, 141), 
                    fontSize: 17)
                ),
              ]
            )
          );
        }
        return ListView.builder(
          itemCount: provider.expenses.length,
          itemBuilder: (context, index) {
            final expense = provider.expenses[index];
            String formattedDate =
                DateFormat('MMM dd, yyyy').format(expense.date);
            return Dismissible(
              key: Key(expense.id),
              direction: DismissDirection.endToStart,
              onDismissed: (direction) {
                provider.removeExpense(expense.id);
              },
              background: Container(
                color: Colors.red,
                padding: EdgeInsets.symmetric(horizontal: 20),
                alignment: Alignment.centerRight,
                child: Icon(Icons.delete, color: Colors.white),
              ),
              child: Card(
                color: Colors.purple[50],
                margin: EdgeInsets.symmetric(horizontal: 10, vertical: 12),
                child: ListTile(
                  title: Text(
                      "${getCategoryNameById(context, expense.categoryId)} - ${getTagNameById(context, expense.tag)}"),
                  subtitle: Text(
                      "Total time: ${expense.time} \nDate: $formattedDate \nNote: ${expense.note}"),
                  isThreeLine: true,
                ),
              ),
            );
          },
        );
      },
    );
  }

  Widget buildExpensesByCategory(BuildContext context) {
    return Consumer<ExpenseProvider>(
      builder: (context, provider, child) {
        if (provider.expenses.isEmpty) {
          return const Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center, // Centra en eje Y
              mainAxisSize: MainAxisSize.max,
              children: <Widget>[
                Icon(Icons.lock_clock, size: 64, color: Colors.grey),
                Text("No time entries yet.",
                  style: TextStyle(
                    color: Color.fromARGB(255, 85, 85, 85), 
                    fontSize: 20)
                ),
                Text("Tap the + button to add your first entry.",
                  style: TextStyle(
                    color: Color.fromARGB(255, 141, 141, 141), 
                    fontSize: 17)
                ),
              ]
            )
          );
        }

        // Grouping expenses by category
        var grouped = groupBy(provider.expenses, (Expense e) => e.categoryId);
        return ListView(
          children: grouped.entries.map((entry) {
            String categoryName = getCategoryNameById(
                context, entry.key); // Ensure you implement this function
            return Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                Padding(
                  padding: EdgeInsets.all(8.0),
                  child: Text(
                    "$categoryName",
                    style: TextStyle(
                      fontSize: 18,
                      fontWeight: FontWeight.bold,
                      color: const Color.fromARGB(255, 24, 173, 141),
                    ),
                  ),
                ),
                ListView.builder(
                  physics:
                      NeverScrollableScrollPhysics(), // to disable scrolling within the inner list view
                  shrinkWrap:
                      true, // necessary to integrate a ListView within another ListView
                  itemCount: entry.value.length,
                  itemBuilder: (context, index) {
                    Expense expense = entry.value[index];
                    return ListTile(
                      title: Text(
                          "- ${getTagNameById(context, expense.tag)}: ${expense.time} hours (${DateFormat('MMM dd, yyyy')
                          .format(expense.date)})"),
                    );
                  },
                ),
              ],
            );
          }).toList(),
        );
      },
    );
  }

  // home_screen.dart
  String getCategoryNameById(BuildContext context, String categoryId) {
    var category = Provider.of<ExpenseProvider>(context, listen: false)
        .categories
        .firstWhere((cat) => cat.id == categoryId);
    return category.name;
  }

  String getTagNameById(BuildContext context, String tagId) {
    var tag = Provider.of<ExpenseProvider>(context, listen: false)
        .tags
        .firstWhere((cat) => cat.id == tagId);
    return tag.name;
  }
}