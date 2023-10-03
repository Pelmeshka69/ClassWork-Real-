#include <iostream>

using namespace std;

class Figure {
public:
    string name;
    int square;
    int lineThinkness;
    string lineColor;
    string fillColor;
public:
    virtual void printAll() {
        cout << name << endl;
        cout << "lineThinkness = " << lineThinkness << endl;
        cout << "lineColor = " << lineColor << endl;
        cout << "fillColor = " << fillColor << endl;
    }

    virtual int calculateArea() {
        return 0;
    }

    bool canFitInside(const Figure& other) const {
        return this->square <= other.square;
    }
};

class Circle : public Figure {
public:
    int radius;
    int diameter;

    Circle(string name, int radius, int lineThinkness, string lineColor, string fillColor) {
        this->name = name;
        this->radius = radius;
        this->diameter = 2 * radius;
        this->lineThinkness = lineThinkness;
        this->lineColor = lineColor;
        this->fillColor = fillColor;
        this->square = calculateArea();
    }

    void printAll() {
        Figure::printAll();
        cout << "Radius = " << radius << endl;
        cout << "The diameter = " << diameter << endl;
    }

    int calculateArea() {
        return 3.14 * (radius * radius);
    }
};

class Rectangle : public Figure {
public:
    int width;
    int height;

    Rectangle(string name, int width, int height, int lineThinkness, string lineColor, string fillColor) {
        this->name = name;
        this->width = width;
        this->height = height;
        this->lineThinkness = lineThinkness;
        this->lineColor = lineColor;
        this->fillColor = fillColor;
        this->square = calculateArea();
    }

    void printAll() {
        Figure::printAll();
        cout << "Width = " << width << endl;
        cout << "Height = " << height << endl;
    }

    int calculateArea() {
        return width * height;
    }
};

class Triangle : public Figure {
public:
    int base;
    int height;

    Triangle(string name, int base, int height, int lineThinkness, string lineColor, string fillColor) {
        this->name = name;
        this->base = base;
        this->height = height;
        this->lineThinkness = lineThinkness;
        this->lineColor = lineColor;
        this->fillColor = fillColor;
        this->square = calculateArea();
    }

    void printAll() {
        Figure::printAll();
        cout << "Base = " << base << endl;
        cout << "Height = " << height << endl;
    }

    int calculateArea() {
        return 0.5 * base * height;
    }
};

class Square : public Figure {
public:
    int sideLength;

    Square(string name, int sideLength, int lineThinkness, string lineColor, string fillColor) {
        this->name = name;
        this->sideLength = sideLength;
        this->lineThinkness = lineThinkness;
        this->lineColor = lineColor;
        this->fillColor = fillColor;
        this->square = calculateArea();
    }

    void printAll() {
        Figure::printAll();
        cout << "Side Length = " << sideLength << endl;
    }

    int calculateArea() {
        return sideLength * sideLength;
    }
};

class Trapeze : public Figure {
public:
    int topBase;
    int bottomBase;
    int height;

    Trapeze(string name, int topBase, int bottomBase, int height, int lineThinkness, string lineColor, string fillColor) {
        this->name = name;
        this->topBase = topBase;
        this->bottomBase = bottomBase;
        this->height = height;
        this->lineThinkness = lineThinkness;
        this->lineColor = lineColor;
        this->fillColor = fillColor;
        this->square = calculateArea();
    }

    void printAll() {
        Figure::printAll();
        cout << "Top Base = " << topBase << endl;
        cout << "Bottom Base = " << bottomBase << endl;
        cout << "Height = " << height << endl;
    }

    int calculateArea() {
        return 0.5 * (topBase + bottomBase) * height;
    }
};

int main() {
    Circle circle("Circle", 5, 2, "Blue", "Yellow");
    Rectangle rectangle("Rectangle", 4, 6, 1, "Red", "Green");
    Triangle triangle("Triangle", 3, 7, 3, "Purple", "Orange");
    Square square("Square", 4, 1, "Black", "White");
    Trapeze trapeze("Trapeze", 5, 9, 4, 2, "Brown", "Gray");

    circle.printAll();

    double circleArea = circle.calculateArea();
    cout << "The area of " << circle.name << " is " << circleArea << endl << "\n";

    rectangle.printAll();

    int rectangleArea = rectangle.calculateArea();
    cout << "The area of " << rectangle.name << " is " << rectangleArea << endl << "\n";

    triangle.printAll();

    double triangleArea = triangle.calculateArea();
    cout << "The area  " << triangle.name << " is " << triangleArea << endl << "\n";

    square.printAll();

    int squareArea = square.calculateArea();
    cout << "The area " << square.name << " is " << squareArea << endl << "\n";

    trapeze.printAll();

    double trapezeArea = trapeze.calculateArea();
    cout << "The area " << trapeze.name << " is " << trapezeArea << endl << "\n";

    if (circle.canFitInside(rectangle)) {
        cout << circle.name << " can fit inside " << rectangle.name << endl;
    }
    else {
        cout << circle.name << " cannot fit inside " << rectangle.name << endl;
    }

    if (square.canFitInside(circle)) {
        cout << square.name << " can fit inside " << circle.name << endl;
    }
    else {
        cout << square.name << " cannot fit inside " << circle.name << endl;
    }

    return 0;
}
