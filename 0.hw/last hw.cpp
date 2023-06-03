#include <iostream>

struct Point {
	int x = 0;
	int y = 0;

	Point& operator>>(const Point& a, const Point& b) {
		x = a;
		y = b;
	}

	Point operator<<(const Point& a, const Point& b) {
		
	}


};


int main() {
 	Point p1(1, 3);
 	Point p2(2, 4);
 	Point p3();
 	Point p4();



}