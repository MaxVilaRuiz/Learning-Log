// import 'package:flutter/material.dart';

// void main() => runApp(MyApp());

// Styling a widget `TextStyle()`
// class MyApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       home: Scaffold(
//         appBar: AppBar(
//           title: Text('Flutter Styling Example'),
//         ),
//         body: Center(
//           child: Center(
//             'Hello, Flutter!',
//             style: TextStyle(
//               fontSize: 24,
//               fontWeight: FontWeight.bold,
//               color: Colors.blue,
//             ),
//           ),
//         ),
//       ),
//     );
//   }
// }


// To apply style across multiples widgets use `ThemeData()`
// class MyApp2 extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       theme: ThemeData(
//         primarySwatch: Colors.blue,
//         textTheme: TextTheme(
//           bodyText2: TextStyle(
//             fontSize: 18,
//             color: Colors.black87
//           ),
//         ),
//       ),
//       home: Scaffold(
//         appBar: AppBar(
//           title: Text('Flutter Theming Example'),
//         ),
//         body: Center(
//           child: Column(
//             mainAxisAlignment: mainAxisAlignment.center,
//             children: [
//               Text('Hello World'),
//               RaisedButton(
//                 onPressed: () {},
//                 child: Text('Press Me'),
//               ),
//             ],
//           ),
//         ),
//       ),
//     );
//   }
// }


// Styling buttons
// Elevated button
// class MyApp3 extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       home: Scaffold(
//         appBar: AppBar(
//           title: Text('Flutter Button Styling'),
//         ),
//         body: Center(
//           child: ElevatedButton(
//             onPressed: () {},
//             style: ElevatedButton.styleFrom( // `styleFrom()` to customize buttons
//               primary: Colors.green, // Background color
//               onPrimary: Colors.white, // Text color
//               padding: EdgeInsets.symmetric(horizontal: 30, vertical: 15),
//               textStyle: TextStyle(
//                 fontSize: 18,
//                 fontWeight: FontWeight.bold,
//               ),
//             ),
//             child: Text('Press Me'),
//           ),
//         ),
//       ),
//     );
//   }
// }


// Using custom fonts
//  - Update the pubspec.yaml:
      // flutter:
      //   fonts:
      //     - family: CustomFont
      //       fonts:
      //         - assets: assets/fonts/CustomFont-Regular.ttf
//  - On .dart doc:
//         bodyText1: TextStyle(fontFamily: 'CustomFont'),


// Customazing containers
// class MyApp3 extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       home: Scaffold(
//         appBar: AppBar(
//           title: Text('Flutter Container Styling'),
//         ),
//         body: Center(
//           child: Container(
//             padding: EdgeInserts.all(20),
//             margin: EdgeInsets.all(20),
//             decoration: BoxDecoration(
//               color: Colors.amber,
//               borderRadius: BorderRadius.circular(15),
//               boxShadow: [
//                 BoxShadow(
//                   color: Colors.black26,
//                   blurRadius: 10,
//                   offset: Offset(2, 2),
//                 ),
//               ],
//             ),
//             child: Text('Styled Conteiner'),
//           ),
//         ),
//       ),
//     );
//   }
// }