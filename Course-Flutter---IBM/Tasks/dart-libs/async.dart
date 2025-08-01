import 'dart:async';

void main() async {
  Future<String> fetchData() async {
    await Future.delayed(Duration(seconds: 2));
    return 'Data fetched!';
  }

  String data = await fetchData();
  print(data);
}