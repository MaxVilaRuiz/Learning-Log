import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart'; // To open URLs in a browser or another app

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Plugin Lab',
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Explore Plugins in Flutter'),
        ),
        body: Center(
          child: ElevatedButton(
            onPressed: _launchURL,
            child: const Text('Open Flutter Website'),
          ),
        ),
      ),
    );
  }
}

void _launchURL() async {
  const url = 'https://flutter.dev'; // Defines the url to be open
  if (await canLaunch(url)) { // Checks if the URL can be launched using the canLaunch function provided by the url_launcher package.
    await launch(url); // If the URL can be launched, this line launches the URL in the default browser.
  } else {
    throw 'Could not launch $url';
  }
}