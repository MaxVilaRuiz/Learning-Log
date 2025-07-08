void navs() {
  // Stack navigation
  //  - The next screen is moved on top of the previous (ex: shopping app)
  // Navigator.push(
  //   context,
  //   MaterialPageRoute(builder: (context) => ProductDetailScreen(product: product),);
  // )

  // Tab navigation
  //  - To switch rapidly between screens (ex: homepage -> profile -> search page...)
  // TabBar(
  //   tabs: [Tab(icon: Icon(Icons.directions_car)), Tab(icon: Icon(Icons.directions_transit))]
  // );

  // Drawer navigation (traditional sidebar / navbar)
  // Drawer(
  // child: ListView(
  //   children: <Widget>[
  //     DrawerHeader(child: Text('Header')),
  //     ListTile(title: Text('Item 1'), onTap: () {}),
  //   ],
  // ),
  // );

  // Bottom navigation bar
  //  - Provides navigation between top-level views of an app through a series of tabs at the bottom of the screen
  // BottomNavigationBar(
  // items: <BottomNavigationBarItem>[
  //   BottomNavigationBarItem(icon: Icon(Icons.home), label: 'Home'),
  //   BottomNavigationBarItem(icon: Icon(Icons.business), label: 'Business'),
  // ],
  // onTap: (index) { /* Handle tap */ },
  // );
}