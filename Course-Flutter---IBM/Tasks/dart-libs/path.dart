import 'package:path/path.dart' as p;

void main() {
  var fullPath = p.join('directory', 'file.txt');
  print('Full path: $fullPath');
}