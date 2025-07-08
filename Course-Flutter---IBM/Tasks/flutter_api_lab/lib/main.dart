import 'package:flutter/material.dart';
import 'package:http/http.dart' as http; // For HTTP requests
import 'dart:convert'; // For decoding JSON
import 'post_model.dart'; // For model classes

Future<List<Post>> fetchPosts() async {
  try {
    final response = await http.get(Uri.parse('https://jsonplaceholder.typicode.com/posts')).timeout(const Duration(seconds: 10));

    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((post) => Post.fromJson(post)).toList();
    } else {
      throw Exception('Failed to load posts');
    }
  } catch (e) {
    throw Exception('Failed to load posts: $e');
  }
}

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter API Lab',
      home: const PostList(),
    );
  }
}

class PostList extends StatefulWidget { //  A stateful widget that allows dynamic content.
  const PostList({super.key});

  @override
  _PostListState createState() => _PostListState(); // Creates the mutable state for PostList to manage data fetching and display.
}

class _PostListState extends State<PostList> { //  Manages the state for PostList
  late Future<List<Post>> futurePosts;

  @override
  void initState() {
    super.initState();
    futurePosts = fetchPosts(); // Initiates the API call to fetch posts when the widget is initialized.
  }

  @override
Widget build(BuildContext context) {
  return Scaffold(
    appBar: AppBar(
      title: const Text('API Data'),
    ),
    body: FutureBuilder<List<Post>>( //  Reacts to the future (futurePosts) and rebuilds the UI depending on the state of the data fetching (loading, error, or success).
      future: futurePosts,
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator()); // Shows a loading indicator (CircularProgressIndicator) while waiting.
        } else if (snapshot.hasError) {
          return Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                const Text('Failed to load data.'),
                Text('Error: ${snapshot.error}'),
                ElevatedButton(
                  onPressed: () {
                    setState(() {
                      futurePosts = fetchPosts(); // Retry fetching data
                    });
                  },
                  child: const Text('Retry'),
                ),
              ],
            ),
          );
        } else if (snapshot.hasData) {
          return ListView.builder(
            itemCount: snapshot.data!.length,
            itemBuilder: (context, index) {
              return ListTile(
                title: Text(snapshot.data![index].title),
                subtitle: Text(snapshot.data![index].body),
              );
            },
          );
        } else {
          return const Center(child: Text('No data available'));
        }
      },
    ),
  );
}
}