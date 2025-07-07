void exercise1() {
  int age = 25;
  double height = 5.9;
  String name = "John Doe";
  bool isStudent = true;

  print('Name: $name');
  print('Age: $age');
  print('Height: $height');
  print('Is a Student: $isStudent');
}

void exercise2() {
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];
  Map<String, int> scores = {'Alice': 90, 'Bob': 85, 'Charlie': 95};
  String? nullableString = null;

  print('Fruits: $fruits');
  print('Score of Alice: ${scores['Alice']}');
  print('Nullable String: $nullableString');
}

void exercise3() {
    var city = 'New York';  // Type inferred as String
    String country = 'USA';  // Type annotation

    print('City: $city');
    print('Country: $country');
}

void exercise4() {
    const double pi = 3.14;
    final DateTime currentTime = DateTime.now();

    print('Pi: $pi');
    print('Current Time: $currentTime');
}

void greet(String name) {
  print('Hello, $name!');
}

class Person {
  String name;
  int age;

  Person(this.name, this.age);

  void displayInfo() {
    print('Name: $name, Age: $age');
  }
}

void main() {
  exercise1();
  exercise2();
  exercise3();
  exercise4();
  greet('Alice');
  Person person = Person('Bob', 30);
  person.displayInfo();
}