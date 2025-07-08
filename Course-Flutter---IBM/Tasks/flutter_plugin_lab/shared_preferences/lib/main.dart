import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart'; // To store data locally on the device

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  TextEditingController _controller = TextEditingController(); // A controller used to read the current value of the text field and manage the text input.
  String _storedValue = '';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Plugin Lab',
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Explore Plugins in Flutter'),
        ),
        body: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
           TextField(
             controller: _controller,
             decoration: const InputDecoration(labelText: 'Enter some text'),
           ),
           const SizedBox(height: 16), // Adds space between TextField and Save button
           ElevatedButton(
             onPressed: _saveData,
             child: const Text('Save Data'),
           ),
           const SizedBox(height: 16), // Adds space between Save and Load button
           ElevatedButton(
             onPressed: _loadData,
             child: const Text('Load Data'),
           ),
           const SizedBox(height: 16), // Adds space between Load button and Text
           Text('Stored Value: $_storedValue'),
         ],
          ),
        ),
      ),
    );
  }

  void _saveData() async {
    SharedPreferences prefs = await SharedPreferences.getInstance(); // Retrieves an instance of the shared preferences.
    await prefs.setString('myKey', _controller.text); // Saves the text entered in the text field under the key 'myKey'.
  }

  void _loadData() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    setState(() {
      _storedValue = prefs.getString('myKey') ?? 'No Data'; // Loads the stored text under the key 'myKey' or sets 'No Data' if no data is found.
    });
  }
}