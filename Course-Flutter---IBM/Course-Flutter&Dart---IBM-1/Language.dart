void variables() {
  // Types of variables
  var name = "Max"; // var: declare a variable without specifying its type explicitly
  const age = 19; // const: declares compile-time constants
  final pi = 3.1416; // final: declares a variable that can only be set once 


  // Data types:
  int students = 30;
  double euler = 2.71828;
  String surname = 'Vilà';
  String message = 'My surname is: $surname'; // String interpolation
  bool condition = true;
  String? nullableString = null;

  // Data structures
  List<String> fullname = ['Max', 'Vilà', 'Ruiz'];
  print(fullname[0]); // 'Max'
  fullname.add('Ponce');

  Map<String, int> scores = {
    'Alice': 90,
    'Bob': 85,
    'Charlie': 95,
  };
  print(scores['Alice']);
  scores['Dave'] = 88;
}


void functions() {
  // Parameters
  // Required params
  int multiply(int a, int b) {
    return a * b;
  }

  // Optional params (use [])
  String fullName(String firstName, [String? middleName, String? lastName]) { // The second and third params are optional
    return '$firstName ${middleName ?? ''} ${lastName ?? ''}';
  }

  // Named params (required or default values - use {})
  void greet({required String name, String greeting = 'Hello'}) {
    print('$greeting, $name!');
  }
  greet(name: 'Alice'); // Output: Hello, Alice!
  greet(name: 'Bob', greeting: 'Hi'); // Output: Hi, Bob!

  // Default params
  // As shown in the last function

  // Arrow function
  Function makeAdder(int addBy) {
    return (int i) => addBy + i;
  }
  var add2 = makeAdder(2);
  print(add2(3)); // Output: 5

  // Anonimous functions (ideal for short operations)
  var list = ['apples', 'bananas', 'oragnes'];
  list.forEach((item) {
    print(item);
  });
}


class General {
  // Public properties
  String name;
  int age;
  double radius;

  // Private property
  String _ssn; // Distingued by the '_' prefix
  double _width;

  // Constructor
  General(this.name, this.age, this._ssn, this.radius, this._width);

  // Methods
  void displayInfo() {
    print('Name: $name, Age: $age, SSN: $_ssn');
  }

  // Getter (for calculating or formatting)
  double get area => 3.14 * radius * radius;

  // Setter (for assignments)
  void set width(double value) {
    if (value > 0) _width = value;
  }

  // Static methods (for utility functions - do not require object access)
  static double pi = 3.14;
  static int square(int x) {
    return x * x;
  }
}
void main () {
  General person1 = General('Alice', 30, '123-45-6789', 1.22, 1.88);
  person1.displayInfo();

  print(General.pi);
  print(General.square(4));
}