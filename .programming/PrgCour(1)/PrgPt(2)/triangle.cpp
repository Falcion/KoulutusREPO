#include "triangle.h"

#include <iostream>

using namespace std;

void triangle::show() {
	cout << "[TRIANGLE] SIDES: " << this->a << ", " << this->b << ", " << this->c << ";" << endl;
}

float triangle::perimeter() {
	return (this->a + this->b + this->c);
}

float triangle::square() {
	float per = this->perimeter() / 2;

	float square = sqrtf(per * (per - this->a) * (per - this->b) * (per - this->c));

	return square;
}

bool triangle::exst_tr() {
	return ((this->a + this->b > this->c) && (this->b + this->c > this->a) && (this->a + this->c > this->b));
}

void triangle::set(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
}