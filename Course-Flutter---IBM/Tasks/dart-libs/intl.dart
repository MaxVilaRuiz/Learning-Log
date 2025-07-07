import 'package:intl/intl.dart';

void main() {
  var now = DateTime.now();
  var formatter = DateFormat('yyyy-MM-dd');
  String formattedDate = formatter.format(now);
  print('Formatted date: $formattedDate');
}