#include <iostream>
#include <vector>
#include <algorithm>
#include "Square.h"
using namespace std;

// Point
Point::Point(int px, int py) { setX(px); setY(py); }
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

// Square
Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), side(s), name(n) {
    area = s * s;
}
unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int s) { side = s; area = s * s; }
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(string n) { name = n; }

int main() {
    int N;
    cin >> N;
    vector<Square> v;
    for (int i = 0; i < N; i++) {
        string name;
        int x, y;
        unsigned int s;
        cin >> name >> x >> y >> s;
        v.emplace_back(name, x, y, s);
    }

    cout << endl;

    cout << "Squares in increasing order of area" << endl;
    sort(v.begin(), v.end(), [](const Square &a, const Square &b) {
        if (a.getArea() != b.getArea()) return a.getArea() < b.getArea();
        if (a.getX() != b.getX()) return a.getX() < b.getX();
        return a.getY() < b.getY();
    });
    for (auto &sq : v)
        cout << sq.getName() << "(" << sq.getX() << ", " << sq.getY() << ") side="
             << sq.getSide() << ", area=" << sq.getArea() << endl;

    cout << endl;

    cout << "Squares in increasing order of max x-coordinate" << endl;
    sort(v.begin(), v.end(), [](const Square &a, const Square &b) {
        int ax = a.getX() + a.getSide();
        int bx = b.getX() + b.getSide();
        if (ax != bx) return ax < bx;
        if (a.getY() != b.getY()) return a.getY() < b.getY();
        return a.getArea() < b.getArea();
    });
    for (auto &sq : v)
        cout << sq.getName() << "(" << sq.getX() + sq.getSide() << ", " << sq.getY()
             << ") side=" << sq.getSide() << ", area=" << sq.getArea() << endl;

    cout << endl;

    cout << "Squares in increasing order of max y-coordinate" << endl;
    sort(v.begin(), v.end(), [](const Square &a, const Square &b) {
        int ay = a.getY() + a.getSide();
        int by = b.getY() + b.getSide();
        if (ay != by) return ay < by;
        if (a.getX() != b.getX()) return a.getX() < b.getX();
        return a.getArea() < b.getArea();
    });
    for (auto &sq : v)
        cout << sq.getName() << "(" << sq.getX() << ", " << sq.getY() + sq.getSide()
             << ") side=" << sq.getSide() << ", area=" << sq.getArea() << endl;

    return 0;
}
