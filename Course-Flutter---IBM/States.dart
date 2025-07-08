// Essencial to separate business logic from the UI and optimize performance to its fullest potential
// Advice: avoid relying only on setState() for every small widget update

// Basic state managemente techniquest: 
// setState()
// class Counter extends StatefulWidget { // Defines a widget that can maintain some state (StatefulWidget)
//   @override
//   _CounterState createState() => _CounterState(); // Creates a _CounterState class to manage the state of the Counter widget
// }

// class _CounterState extends State<Counter> {
//   int _counter = 0;

//   void _incrementCounter() {
//     setState(() {
//       _counter++;
//     });
//   }

//   // Builds the UI
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(title: Text('Counter')),
//       body: Center(
//         child: Column(
//           mainAxisAligment: MainAxisAligment.center,
//           children: <Widget> [
//             Text('You have pushed the button this many times: '),
//             Text('$_counter', style: Theme.of(context).textTheme.headline4),
//           ],
//         ),
//       ),
//       floatingActionButton: FloatingActionButton(
//         onPressed: _incrementCounter,
//         tooltip: 'Increment',
//         child: Icon(Icons.add),
//       ),
//     );
//   }
// }

// InheritedWidget()
// More complex state management. Allows passing data down the widget tree
// class MyInheritedWidget extends InheritedWidget {
//   final int data;

//   MyInheritedWidget({required this.data, required Widget child}) : super(child: child);

//   @override
//   bool udpateShouldNotify(covariant MyInheritedWidget oldWidget) { // Checks if the data has changed
//     return oldWidget.data != data;
//   }

//   static MyInheritedWidget? of(BuildContext context) { // Provides a way to access the data from the widget tree
//     return context.dependOnInheritedWidgetOfExactType<MyInheritedWidget>();
//   }
// }

// class ParentWidget extends StatefulWidget {
//   @override
//   _ParentWidgetState createState() => _ParentWidgetState();
// }

// class _ParentWidgetState extends State<ParentWidget> {
//   int counter = 0;

//   void incrementCounter() {
//     setState(() {
//       counter++;
//     });
//   }

//   @override
//   Widget build(BuildContext context) {
//     return MyInheritedWidget(
//       data: counter,
//       child: Scaffold(
//         appBar: AppBar(title: Text('Inherited Widget Example')),
//         body: Center(child: ChildWidget()),
//         floatingActionButton: FloatingActionButton(
//           onPressed: incrementCounter,
//           tooltip: 'Increment',
//           child: Icon(Iconcs.add),
//         )
//       )
//     );
//   }
// }

// class ChildWidget extends StatelessWidget { // Displays a stateless widget that reads the counter value and shows it as text
//   @override
//   Widget build(BuildContext context) {
//     final inheritedData = MyInheritedWidget.of(context)?.data ?? 0;
//     return Text('Counter value: $inheritedData');
//   }
// }