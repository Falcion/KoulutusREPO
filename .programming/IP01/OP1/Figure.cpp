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

	this->side1 = calculate_side(x1, x2, y1, y2);
	this->side2 = calculate_side(x2, x3, y2, y3);
	this->side3 = calculate_side(x3, x4, y3, y4);
	this->side4 = calculate_side(x1, x4, y1, y4);

	float diag1 = calculate_side(x1, x3, y1, y3);
	float diag2 = calculate_side(x2, x4, y2, y4);

	this->P = side1 + side2 + side3 + side4;

	float coords_sumpo = (x1 + x3) * (x2 + x4) + (y1 * y3) * (y2 * y4);
	float coords_define = sqrt(pow(x1 + x3, 2) + pow(y1 + y3, 2)) * sqrt(pow(x2 + x4, 2) + pow(y2 + y4, 2));

	float cos = coords_sumpo / coords_define;

	float sin = sqrt(abs(1 - pow(cos, 2)));

	this->S = 0.5 * diag1 * diag2 * sin;
}

float Figure::calculate_side(float x1, float x2, float y1, float y2) {
	float x12 = abs(x2 - x1);
	float y12 = abs(y2 - y1);

	return sqrt(pow(x12, 2) + pow(y12, 2));
}

bool Figure::is_prug() {
	float sin = S / (this->side1 * this->side2);

	double degrees = asin(sin);

	return (degrees > 89.7 && degrees < 90.3);
}

void Figure::show() {
	cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << ";" << endl;
	cout << "Square: " << this->S << ", " << "perimeter: " << this->P << endl;
}

bool Figure::is_square() {
	bool is_pr = is_prug();
	
	return (side1 == side2 == side3 == side4 && is_pr);
}

bool Figure::is_romb() {
	bool is_pr = is_prug();

	if (side1 == side2 == side3 == side4 && is_pr == false)
		return true;
	else
		return false;
}

bool Figure::is_in_circle() {
	float P1 = this->P / 2;
	float S1 = sqrt((P1 - side1) * (P1 - side2) * (P1 - side3) * (P1 - side4));
	return (S1 == S);
}

bool Figure::is_out_circle() {
	return (side1 + side3 == side2 + side4);
}