#include "Triangle.h";
#include <iostream>
#include <cmath>

bool Triangle:: exst_tr() {
	return ((a + b > c) && (b + c > a) && (a + c > b));
}

void Triangle::set(double a1, double b1, double c1) {
	this->a = a1;
	this->b = b1;
	this->c = c1;
}

void Triangle::show() {
	cout << "1st side: " << a << endl;
	cout << "2nd side: " << b << endl;
	cout << "3rd side: " << c << endl;
}

double Triangle::perimetr() {
	double p = a + b + c;
	return p;
}

double Triangle::square() {
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}