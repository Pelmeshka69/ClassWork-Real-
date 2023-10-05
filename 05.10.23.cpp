#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};

class Line : public Point {
public:
    Point p1;
    Point p2;
    Point p3;
    double length;

    Line(Point p1, Point p2)  {
        if (p2.x >= p1.x && p2.y >= p1.y) {
            length = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
        }
        else {
            length = sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
        }
    }
};

class Triangle {
public:
    Point p1;
    Point p2;
    Point p3;

    Triangle(Point p1, Point p2, Point p3) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }

    double distance(Point a, Point b) {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }

    double area() {
        double a = distance(p1, p2);
        double b = distance(p2, p3);
        double c = distance(p3, p1);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Point point1(2, 4);
    Point point2(6, 1);
    Point point3(2, 2);
    Triangle triangle(point1, point2, point3);
    cout << triangle.area() << endl;
    return 0;
}
