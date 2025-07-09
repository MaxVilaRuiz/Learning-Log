class Expense {
  final String id;
  final double time;
  final String categoryId; // This will link to ExpenseCategory
  final String payee;
  final String note;
  final DateTime date;
  final String tag; // This assumes you have a tagging system. Adjust if needed.

  Expense({
    required this.id,
    required this.time,
    required this.categoryId,
    required this.payee,
    required this.note,
    required this.date,
    required this.tag, 
  });

  // Convert a JSON object to an Expense instance
  factory Expense.fromJson(Map<String, dynamic> json) {
    return Expense(
      id: json['id'],
      time: json['time'],
      categoryId: json['categoryId'],
      payee: json['payee'],
      note: json['note'],
      date: DateTime.parse(json['date']),
      tag: json['tag'],
    );
  }

  // Convert an Expense instance to a JSON object
  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'time': time,
      'categoryId': categoryId,
      'payee': payee,
      'note': note,
      'date': date.toIso8601String(),
      'tag': tag,
    };
  }
}