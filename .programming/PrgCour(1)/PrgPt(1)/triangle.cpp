#include "triangle.h"

#include <iostream>

using namespace std;

void triangle::show() {
	cout << "[TRIANGLE] Sides of current triangle (ABC): " << a << ", " << b << ", " << c << ";" << endl;
}

double triangle::perimetr() {
	return (a + b + c);
}

double triangle::square() {
	double per = perimetr() / 2;

	double square = sqrt(per * (per - a) * (per - b) * (per - c));

	return square;
}

bool triangle::exst_tr() {
	return ((a + b > c) && (b + c > a) && (a + c > b));
}
void triangle::set(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
}
