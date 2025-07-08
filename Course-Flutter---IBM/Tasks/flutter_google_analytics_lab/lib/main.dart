import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
// import 'firebase_options.dart';
import 'package:firebase_analytics/firebase_analytics.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
    // options: DefaultFirebaseOptions.currentPlatform,
  );
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // Access the FirebaseAnalytics instance
  static final FirebaseAnalytics analytics = FirebaseAnalytics.instance;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Firebase Analytics Demo',
      home: MyHomePage(analytics: analytics),
    );
  }
}

class MyHomePage extends StatefulWidget {
  final FirebaseAnalytics analytics;

  MyHomePage({Key? key, required this.analytics}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  void _logButton1Event() {
    widget.analytics.logEvent(
      name: 'button_1_clicked',
      parameters: {'button_name': 'Button 1'},
    );
    print('Button 1 clicked event logged');
  }

  void _logButton2Event() {
    widget.analytics.logEvent(
      name: 'button_2_clicked',
      parameters: {'button_name': 'Button 2'},
    );
    print('Button 2 clicked event logged');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Firebase Analytics Demo'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            ElevatedButton(
              onPressed: _logButton1Event,
              child: Text('Log Button 1 Event'),
            ),
            SizedBox(height: 20), // Adds space between the two buttons
            ElevatedButton(
              onPressed: _logButton2Event,
              child: Text('Log Button 2 Event'),
            ),
          ],
        ),
      ),
    );
  }
}