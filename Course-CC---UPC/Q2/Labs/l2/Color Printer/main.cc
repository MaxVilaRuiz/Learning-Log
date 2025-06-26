#include <iostream>
#include <vector>
#include "color-printer.hh"
using namespace std;

int main() {
	ColorPrinter pr;
	pr.set_color(Color::red);
	pr << "Hello, red!" << std::endl;

	pr.set_color(Color::green);
	pr << "Hello, green!" << endl << 13 << endl;

	pr.set_color(Color::blue);
	pr << "This should be in blue" << endl << "... and this" << endl;

	std::vector<pair<Color, string>> colors = {
		{Color::black, "black"},   {Color::red, "red"},		{Color::green, "green"},
		{Color::yellow, "yellow"}, {Color::blue, "blue"},	{Color::magenta, "magenta"},
		{Color::cyan, "cyan"},	   {Color::white, "white"},
	};

	for (int i = 0; i < colors.size(); i++) {
		pr.set_color(colors[i].first);
		pr << colors[i].second << " ";
	}
	pr << endl;

	return 0;
}