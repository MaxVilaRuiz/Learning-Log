void basicWidgets() {
  // Text:
  // Text('Hello, Flutter!');

  // Img:
  // Image.network('https://example.com/image.png')

  // Icon:
  // Icon(Icons.star);

  // Button:
  // ElevatedButton(
  //   onPressed: () {},
  //   child: Text('Press Me'),
  // )
}

void layoutWidgets() {
  // Column: vertical arrangement
  // Column(
  //   children: <Widget> [
  //     Text('First item'),
  //     Text('Second item'),
  //   ]
  // )

  // Row: horitzontal arrangement
  // Row(
  //   children: <Widget> [
  //     Text('First item'),
  //     Text('Second item'),
  //   ]
  // )

  // Container: groups and styles other widgets...
  // Container(
  //   padding: EdgeInsets.all(16.0),
  //   color: Colors.blue,
  //   child: Text('This is inside a container'),
  // )

  // Stack: overlaps on top of each other
  // Stack(
  //   children: <Widget> [
        // Container(color: Colors.blue, width: 100, height: 100),
        // Container(color: Colors.blue, width: 100, height: 100),
  //   ]
  // )

  // 
}

void inputWidgets() {
  // Text Field
  // TextField(
  //   decoration: InputDecoration(labelText: 'Enter your name'),
  // )

  // Checkbox
  // Checkbox(
  //   value: true,
  //   onChange: (bool? value) {},
  // )

  // Radio (allows single option selection)
  // Radio(
  //   valu: 1,
  //   groupValue: selectedValue,
  //   onChanged: (int? value) {},
  // )

  // Switch (toggle between on/off states)
  // Switch(
  //   value: true,
  //   onChanged: (bool value) {},
  // )
}

void buttonWidgets() {
  // Evevated Button:
  // ElevatedButton(
  //   onPressed: () {},
  //   child: Text('Press Me'),
  // )

  // Text Button (flat button)
  // TextButton(
  //   onPressed: () {},
  //   child: Text('Text Button'),
  // )

  // Icon Button:
  // IconButton(
  //   onPressed: () {},
  //   icon: Icon(Icons.thumb_up),
  // )

  // DropdownButton
  //   DropdownButton<String>(
  //   value: dropdownValue,
  //   onChanged: (String newValue) {
  //     setState(() {
  //       dropdownValue = newValue;
  //     });
  //   },
  //   items: <String>['One', 'Two', 'Three', 'Four']
  //     .map<DropdownMenuItem<String>>((String value) {
  //       return DropdownMenuItem<String>(
  //         value: value,
  //         child: Text(value),
  //       );
  //     }).toList(),
  // )

  // List-view 
  //   ListView.builder(
  //   itemCount: items.length,
  //   itemBuilder: (context, index) {
  //     return ListTile(title: Text(items[index]));
  //   },
  // )

  // Snack Bar
  //  - Provides lightweight feedback about an operation by showing a brief message
  //   final snackBar = SnackBar(content: Text('Yay! A SnackBar!'));
  // ScaffoldMessenger.of(context).showSnackBar(snackBar);

  // Dialogs
  //     showDialog(
  //   context: context,
  //   builder: (BuildContext context) {
  //     return AlertDialog(
  //       title: Text('Alert!'),
  //       content: Text('You have been alerted.'),
  //       actions: <Widget>[
  //         TextButton(
  //           onPressed: () {
  //             Navigator.of(context).pop();
  //           },
  //           child: Text('Close'),
  //         ),
  //       ],
  //     );
  //   },
  // );

  // Expasion pannel
  //   - Provides a way to expand and collapse content
  //   ExpansionPanelList(
  //   expansionCallback: (int index, bool isExpanded) {
  //     setState(() {
  //       items[index].isExpanded = !isExpanded;
  //     });
  //   },
  //   children: items.map<ExpansionPanel>((Item item) {
  //     return ExpansionPanel(
  //       headerBuilder: (BuildContext context, bool isExpanded) {
  //         return ListTile(title: Text(item.headerValue));
  //       },
  //       body: ListTile(title: Text(item.expandedValue)),
  //       isExpanded: item.isExpanded,
  //     );
  //   }).toList(),
  // )
}

void listWidgets() {
  // List View (scrollable list)
  // ListView(
  //   children: <Widget> [
  //     ListTitle(
  //       leading: Icon(Icons.map),
  //       title: Text('Map'),
  //     ),
  //     ListTitle(
  //       leading: Icon(Icons.photo_album),
  //       title: Text('Album'),
  //     ),
  //   ]
  // )
}