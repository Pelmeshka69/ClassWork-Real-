#include <iostream>
#include <vector>
#include <cmath> // Для використання sqrt()

using namespace std;

class Point {
private:
	int x = 0,
		y = 0;
public:
	Point() {

	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showCoords() {
		cout << "x: " << this->x << endl;
		cout << "y: " << this->y << "\n" << endl;
	}
	double distance() { // Метод для обчислення дистанції
		return sqrt(x * x + y * y);
	}
	Point midpoint(Point other) { // Доданий метод для обчислення серединної точки
		return Point((this->x + other.x) / 2, (this->y + other.y) / 2);
	}
};

int main()
{
	vector <Point> system = { {0,0},{10,7},{-3,5},{8,0},{1,11},{-10,-10},{2,25} };
	for (int i = 0; i < system.size() - 1; i++) {
		system[i].showCoords();
		cout << "Distance: " << system[i].distance() << "\n" << endl; // Виведення дистанції для кожної точки
		Point mid = system[i].midpoint(system[i + 1]); // Обчислення серединної точки між поточною точкою та наступною
		cout << "Midpoint with next point: ";
		mid.showCoords();
	}
}
