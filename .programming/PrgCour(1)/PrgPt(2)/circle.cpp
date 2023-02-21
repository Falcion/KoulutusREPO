#define _USE_MATH_DEFINES

#include "circle.h";
#include "triangle.h";

#include <iostream>
#include <math.h>

using namespace std;

circle::circle(float radius, float x_cntr, float y_cntr) {
	this->radius = radius;
	this->x_center = x_cntr;
	this->y_center = y_cntr;
}

void circle::show() {
	cout << "[CIRCLE] Radius: " << this->radius << ";" << endl;
	cout << "[CIRCLE] Center coords: (" << this->x_center << ", " << this->y_center << ");" << endl;

	cout << "[CIRCLE] Square: " << square() << ";" << endl;
}

bool circle::triangle_in(float a, float b, float c) {
	triangle tr;

	tr.set(a, b, c);

	float rad = (a * b * c) / (4 * tr.square());

	return (rad == this->radius);
}

bool circle::triangle_around(float a, float b, float c) {
	triangle tr;

	tr.set(a, b, c);

	float rad = tr.square() / (tr.perimeter() / 2);

	return (rad == this->radius);
}

bool circle::check_circle(float r, float x_cntr, float y_cntr) {
	float cntr_dist = sqrtf(pow(this->x_center - x_cntr, 2) + pow(this->y_center - y_center, 2));

	return (cntr_dist < (this->radius + r));
}

void circle::set_circle(float r, float x_cntr, float y_cntr) {
	this->radius = r;
	this->x_center = x_cntr;
	this->y_center = y_cntr;
}

float circle::square() {
	float square = M_PI * pow(this->radius, 2);

	return square;
}