import 'package:flutter/material.dart'; // library that provides built-in widgets to design the UI
import 'package:logger/logger.dart'; // Import the logger package

void main() {
  runApp(const MyApp2()); // Takes provided widget 'MyApp' and makes it the root of the widget tree
}

class MyApp extends StatelessWidget { // To create stateless widget name 'MyApp'
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) { // context param provides info about the location of this widget in the widget tree
    return MaterialApp( // Placeholder for MaterialApp properties
      title: 'Flutter Layout Lab',
      home: Scaffold( // Placeholder for home property. Scaffold provides a framework that implements the basic material design layout structure of the UI
        appBar: AppBar( // AppBar is a material design app bar at the top of the screen
          title: const Text('Flutter Layout Example'),
        ),
        body: const Column(
          children: <Widget>[
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly, // 'mainAxisAlignment' defines how the children should be placed in the x axis
              children: const<Widget>[
                Icon(Icons.star, color: Colors.blue),
                Icon(Icons.favorite, color: Colors.red),
                Icon(Icons.thumb_up, color: Colors.green),
              ],
            ),
            Text('Welcome to Flutter!'),
            Text('Building a layout is easy.'),
          ],
        ),
      ),
    );
  }
}

class MyApp2 extends StatelessWidget {
  const MyApp2({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Layout Lab',
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Flutter Layout Example'),
        ),
        body: MyForm(),
      ),
    );
  }
}
void _showAlertDialog(BuildContext context, String title, String message) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: Text(title),
          content: Text(message),
          actions: [
            TextButton(
              child: const Text('OK'),
              onPressed: () {
                Navigator.of(context).pop(); // Close the dialog
              },
            ),
          ],
        );
      },
    );
}
class MyForm extends StatefulWidget {
  @override
  _MyFormState createState() => _MyFormState();
}
// Logger is commonly used to create log msgs for debugging
// Logger, in this case, is used to print a log msg when the form is valid and the button is pressed
class _MyFormState extends State<MyForm> {
  final _formKey = GlobalKey<FormState>();
  final Logger _logger = Logger(); // Initialize the logger
  @override
  Widget build(BuildContext context) {
    return Form(
      key: _formKey,
      child: Column(
        children: <Widget>[
          const Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: const<Widget>[
              Icon(Icons.star, color: Colors.blue),
              Icon(Icons.favorite, color: Colors.red),
              Icon(Icons.thumb_up, color: Colors.green),
            ],
          ),
          const Text('Welcome to Flutter!'),
          const Text('Building a layout is easy.'),
          TextFormField(
            decoration: const InputDecoration(labelText: 'Enter your name'),
            validator: (value) {
              if (value == null || value.isEmpty) {
                return 'Please enter some text';
              }
              return null;
            },
          ),
          ElevatedButton(
            onPressed: () {
                if (_formKey.currentState!.validate()) {
                  _logger.i('Form is valid. User input is logged.'); // Log the user input
                  _showAlertDialog(context, 'Form Submitted', 'User input is logged.');
                }
            },
            child: const Text('Submit'),
          ),
        ],
      ),
    );
  }
}