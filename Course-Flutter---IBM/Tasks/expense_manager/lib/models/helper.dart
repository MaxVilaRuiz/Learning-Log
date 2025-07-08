import 'dart:convert';
import 'package:shared_preferences/shared_preferences.dart';
import 'category.dart';
import 'expense.dart';
import 'tag.dart';

class LocalStorageService {
  Future<void> saveExpenses(List<Expense> expenses) async {
    final prefs = await SharedPreferences.getInstance();
    final encoded = jsonEncode(expenses.map((e) => e.toJson()).toList());
    await prefs.setString('expenses', encoded);
  }

  Future<List<Expense>> loadExpenses() async {
    final prefs = await SharedPreferences.getInstance();
    final raw = prefs.getString('expenses');
    if (raw != null) {
      final List<dynamic> decoded = jsonDecode(raw);
      return decoded.map((e) => Expense.fromJson(e)).toList();
    }
    return [];
  }


  Future<void> saveCategories(List<Category> categories) async {
    final prefs = await SharedPreferences.getInstance();
    final encoded = jsonEncode(categories.map((c) => c.toJson()).toList());
    await prefs.setString('categories', encoded);
  }

  Future<List<Category>> loadCategories() async {
    final prefs = await SharedPreferences.getInstance();
    final raw = prefs.getString('categories');
    if (raw != null) {
      final List<dynamic> decoded = jsonDecode(raw);
      return decoded.map((c) => Category.fromJson(c)).toList();
    }
    return [];
  }


  Future<void> saveTags(List<Tag> tags) async {
    final prefs = await SharedPreferences.getInstance();
    final encoded = jsonEncode(tags.map((t) => t.toJson()).toList());
    await prefs.setString('tags', encoded);
  }

  Future<List<Tag>> loadTags() async {
    final prefs = await SharedPreferences.getInstance();
    final raw = prefs.getString('tags');
    if (raw != null) {
      final List<dynamic> decoded = jsonDecode(raw);
      return decoded.map((t) => Tag.fromJson(t)).toList();
    }
    return [];
  }
}
