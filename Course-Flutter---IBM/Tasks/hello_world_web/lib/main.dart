import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Hello World Web',
      home: Scaffold(
        appBar: AppBar(
          title: Text('Hello World Web App'),
        ),
        body: Center(
          child: Text(
            'Hello World',
            style: TextStyle(fontSize: 24),
          ),
        ),
      ),
    );
  }
}


// MaterialApp: wraps the entire app and provides material design styling
// Scaffold: provides a basic structure, including an AppBar and a Body
// AppBar: displays the title of the application
// Center: aligns the "Hello World" text to the center of the screen
// Text: displays the "Hello World" message with a font size of 24