#include "Circle.h"
#include "Triangle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(float r, float x, float y) {
	this->radius = r;
	this->x_center = x;
	this->y_center = y;
}

void Circle::set_circle(float r, float x, float y) {
	this->radius = r;
	this->x_center = x;
	this->y_center = y;
}

float Circle::square() {
	float s = M_PI * pow(radius, 2);

	return s;
}

bool Circle::triangle_around(float a, float b, float c) {
	Triangle triangle;
	triangle.set(a, b, c);
	double tr_s = triangle.square();

	// By definition of triangle defined outside of the circle: radius of the circle equals S / ((a+b+c)/2);
	float r = (tr_s) / ((a + b + c) / 2);

	if (r == this->radius)
		return true;
	else
		return false;
}

bool Circle::triangle_in(float a, float b, float c) {
	Triangle triangle;
	triangle.set(a, b, c);
	double tr_s = triangle.square();

	// By definition of triangle defined inside of the circle: radius of the circle equals a*b*c/4S;
	float r = (a * b * c) / (4 * tr_s);

	if (r == this->radius)
		return true;
	else
		return false;
}

bool Circle::check_circle(float r, float x_cntr, float y_cntr) {
	float x_dist = abs(x_cntr - this->x_center);
	float y_dist = abs(y_cntr - this->y_center);

	float dots_dist = sqrt(pow(x_dist, 2) + pow(y_dist, 2));

	if (dots_dist < (this->radius + r))
		return true;
	else
		return false;
}

void Circle::show() {
	cout << "Circle's radius: " << this->radius << endl;
	cout << "Circle's center's X: " << this->x_center << endl;
	cout << "Circle's center's Y: " << this->y_center << endl;
}