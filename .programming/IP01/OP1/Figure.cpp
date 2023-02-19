#include "Figure.h"
#include <math.h>
#include <tgmath.h>
#include <iostream>

Figure::Figure(float x1, float x2, float x3, float x4,
	float y1, float y2, float y3, float y4) {
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;

	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);

	this->P = side1 + side2 + side3 + side4;

	float p = 0.5 * (side1 + side2 + side3 + side4);
	
	float s = sqrt(p * (p - side1) * (p - side2) * (p - side3) * (p - side4));

	this->S = s;
}

float Figure::calculate_side(float x1, float x2, float y1, float y2) {
	float x12 = abs(x2 - x1);
	float y12 = abs(y2 - y1);

	float xy = sqrt(pow(x12, 2) + pow(y12, 2));

	return xy;
}

bool Figure::is_prug() {
	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);

	float sin = S / (side1 * side2);

	double degrees = asin(sin);

	if (degrees > 89.7 && degrees < 90.3)
		return true;
	else
		return false;
}

void Figure::show() {
	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);

	cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << ";" << endl;
	cout << "Square: " << this->S << ", " << "perimeter: " << this->P << endl;
}

bool Figure::is_square() {
	bool is_pr = is_prug();

	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);
	
	if (side1 == side2 == side3 == side4 && is_pr)
		return true;
	else
		return false;
}

bool Figure::is_romb() {
	bool is_pr = is_prug();

	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);

	if (side1 == side2 == side3 == side4 && is_pr == false)
		return true;
	else
		return false;
}

bool Figure::is_in_circle() {
	float diag1 = calculate_side(x1, x3, y1, y3);
	float diag2 = calculate_side(x2, x4, y2, y4);

	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);

	if (diag1 * diag2 == (side1 * side3 + side2 * side4))
		return true;
	else
		return false;
}

bool Figure::is_out_circle() {
	float side1 = calculate_side(x1, x2, y1, y2);
	float side2 = calculate_side(x2, x3, y2, y3);
	float side3 = calculate_side(x3, x4, y3, y4);
	float side4 = calculate_side(x1, x4, y1, y4);

	if (side1 + side3 == side2 + side4)
		return true;
	else
		return false;
}