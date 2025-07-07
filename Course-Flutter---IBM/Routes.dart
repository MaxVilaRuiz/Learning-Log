// import 'package:flutter/material.dart';

// Types of routes:
// CupertinoPageRoute -> iOS apps
// MaterialPageRoute -> Android apps

// Navigation class:
// To go to a new screen: push a route
// To go to the previous screen: remove the actual route (pop)

void main() {
  // runApp(MyApp());
}

// Named routes
// Navigator.pushNamed(context, '/second');

// Example:
// class MyApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//     initialRoute: '/',
//     routes: {
//       '/': (context) => FirstScreen(),
//       '/second': (context) => SecondScreen(),
//     },
//   )
//   }
// }

// class FirstScreen extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('First Screen'),
//       ),
//       body: Center(
//         child: ElevatedButton(
//           onPressed: () {
//             Navigator.pushNamed(context, '/second'); // Screen navigate to the specified route
//           },
//           child: Text('Go to Second Screen'),
//         ),
//       ),
//     );
//   }
// }

// class SecondScreen extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('Second Screen'),
//       ),
//       body: Center(
//         child: ElevatedButton(
//           onPressed: () {
//             Navigator.pop(context, '/second'); // Screen navigate to the specified route
//           },
//           child: Text('Go back to First Screen'),
//         ),
//       ),
//     );
//   }
// }



// Direct routes
//  - Passes the route directly to the Navigator
// Navigator.push(
//   context,
//   MaterialPageRoute(builder: (context) => SecondScreen());
// )

// class MyApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       home: FirstScreen(),
//     );
//   }
// }

// class FirstScreen extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('First Screen'),
//       ),
//       body: Center(
//         child: ElevatedButton(
//           onPressed: () {
//             Navigator.push(
//               context,
//               MaterialPageRoute(builder: (context) => SecondScreen()), // Use params to SecondScreen to pass data between screens
//             );
//           },
//           child: Text('Go to Second Screen'),
//         ),
//       ),
//     );
//   }
// }

// class SecondScreen extends StatelessWidget {
  // // If you are passing data
  // final String data;
  // SecondScreen({required this.data});

//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('Second Screen'),
//       ),
//       body: Center(
//         child: ElevatedButton(
//           onPressed: () {
//             Navigator.pop(context);
//           },
//           child: Text('Go back to the First Screen'),
//         ),
//       ),
//     );
//   }
// }



// Examples of rounting

// Screen navigation:
// Navigator.push(
//   context,
//   MaterialPageRoute(builder: (context) => SecondScreen());
// )

// Data retrieval:
// final result = await Navigation.push(
//   context,
//   MaterialPageRoute(builder: (context) => FormScreen()),
// );

// Removal of screens
// Navigation.pop(context);

// Screen replacement
// Navigator.pushReplacement(
//   context,
//   MaterialPageRoute(builder: (context) => NewScreen()),
// );