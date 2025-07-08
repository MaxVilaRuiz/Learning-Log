// Basic HTTP GET request:
// Future<void> fetchData() async {
//   var response = await
// http.get(Uri.parse('https://api.example.com/data'));
//   print(response.body);
// }

// Handling API Errors:
// try {
//   var response = await 
// http.get(Uri.parse('https://api.example.com/data'));
//   print(response.body);
// } catch (e) {
//   print('Caught error: $e');
// }

// Parsing JSON Data:
// var data = jsonDecode(response.body);
// print('User name: ${data['username']}');

// Async programming:
// Future<void> getUserData() async {
//   var response = await
// http.get(Uri.parse('https://api.example.com/users/1'));
//   var data = jsonDecode(response.body);
//   print('User name: ${data['name']}');
// }

// Post Data to API:
// Future<void> postData() async {
//   var response = await 
// http.post(Uri.parse('https://api.example.com/add'), body: {'name': 'John Doe'});
//   print('Response status: ${response.statusCode}');
// }

// Fetch Data with Headers:
// Future<void> fetchWithHeaders() async {
//   var response = await http.get(
//     Uri.parse('https://api.example.com/data'),
//     headers: {'Authorization': 'Bearer your_token_here'}
//   );
//   print('Data with headers: ${response.body}');
// }