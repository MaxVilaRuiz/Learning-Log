import 'package:flutter/material.dart';
import '../models/expense.dart';
import '../models/category.dart';
import '../models/helper.dart'; 
import '../models/tag.dart';

class ExpenseProvider with ChangeNotifier {
  final LocalStorageService storage;

  List<Expense> _expenses = [];
  List<Category> _categories = [];
  List<Tag> _tags = [];

  List<Tag> get tags => _tags;
  List<Category> get categories => _categories;
  List<Expense> get expenses => _expenses;

  ExpenseProvider(this.storage);

  Future<void> init() async {
    _expenses = await storage.loadExpenses();
    _categories = await storage.loadCategories();
    await _loadTagsFromStorage();
    notifyListeners();
  }


  Future<void> addExpense(Expense expense) async {
    _expenses.add(expense);
    await storage.saveExpenses(_expenses);
    notifyListeners();
  }

  Future<void> addOrUpdateExpense(Expense expense) async {
    int index = _expenses.indexWhere((e) => e.id == expense.id);
    if (index != -1) {
      _expenses[index] = expense;
    } else {
      _expenses.add(expense);
    }
    await storage.saveExpenses(_expenses);
    notifyListeners();
  }

  Future<void> removeExpense(String id) async {
    _expenses.removeWhere((expense) => expense.id == id);
    await storage.saveExpenses(_expenses);
    notifyListeners();
  }


  Future<void> addCategory(Category category) async {
    _categories.add(category);
    await storage.saveCategories(_categories);
    notifyListeners();
  }

  Future<void> removeCategory(String id) async {
    _categories.removeWhere((cat) => cat.id == id);
    await storage.saveCategories(_categories);
    notifyListeners();
  }


  Future<void> addTag(Tag tag) async {
    _tags.add(tag);
    await storage.saveTags(_tags);
    notifyListeners();
  }

  Future<void> removeTag(String id) async {
    _tags.removeWhere((tag) => tag.id == id);
    await storage.saveTags(_tags);
    notifyListeners();
  }


  Future<void> _loadTagsFromStorage() async {
    _tags = await storage.loadTags();
    notifyListeners();
  }
}
