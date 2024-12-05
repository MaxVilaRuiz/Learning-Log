#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    Point distance;
    distance.x = a.x - b.x;
    distance.y = a.y - b.y;
    
    double res;
    res = sqrt((distance.x * distance.x) + (distance.y * distance.y));
    return res;
}

int main() {
    Point distance1, distance2;
    cin >> distance1.x >> distance1.y;
    cin >> distance2.x >> distance2.y;
    cout << dist(distance1, distance2) << endl;
}