#define _USE_MATH_DEFINES

#include "circle.h";
#include "triangle.h";

#include <iostream>
#include <math.h>

using namespace std;

circle::circle(float r, float x, float y) {
	radius = r;
	x_center = x;
	y_center = y;
}

void circle::set_circle(float r, float x, float y) {
	radius = r;
	x_center = x;
	y_center = y;
}

float circle::square() {
	float square = M_PI * pow(radius, 2);

	return square;
}

bool circle::triangle_around(float a, float b, float c) {
	triangle tr;

	tr.set(a, b, c);

	float rad = tr.square() / (tr.perimeter() / 2);

	return (rad == radius);
}

bool circle::triangle_in(float a, float b, float c) {
	triangle tr;

	tr.set(a, b, c);

	float rad = (a * b * c) / (4 * tr.square());

	return (rad == radius);
}

bool circle::check_circle(float r, float x_cntr, float y_cntr) {
	float cntr_dist = sqrtf(pow(x_center - x_cntr, 2) + pow(y_center - y_center, 2));

	return (cntr_dist < (radius + r));
}