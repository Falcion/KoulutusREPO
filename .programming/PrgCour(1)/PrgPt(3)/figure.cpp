#include "figure.h";

#include <iostream>
#include <cmath>

using namespace std;

figure::figure(float x1, float x2, float x3, float x4,
			   float y1, float y2, float y3, float y4) {
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;

	this->s1 =calc_s(x1, x2, y1, y2);
	this->s2 =calc_s(x2, x3, y2, y3);
	this->s3 =calc_s(x3, x4, y3, y4);
	this->s4 =calc_s(x1, x4, y1, y4);

	P = s1 + s2 + s3 + s4;

	float cos = ((((x3 - x1) * (x4 - x2)) + ((y3 - y1) * (y4 - y2))) / ((sqrt((pow((x1 + x3), 2)) + pow((y1 + y3), 2))) + (sqrt((pow((x2 + x4), 2)) + pow((y2 + y4), 2)))));

	float sin = sqrtf(abs(1 - pow(cos, 2)));

	this-> d1 = calc_s(x1, x3, y1, y3);
	this-> d2 = calc_s(x2, x4, y2, y4);

	S = abs(d1 * d2 * sin) / 2;
}

void figure::show() {
	cout << "Coords of ABCD (the same way as input): " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ", " << x4 << ", " << y4 << endl;

	cout << "Sides: " << s1 << ", " << s2 << ", " << s3 << ", " << s4 << ";" << endl;
	cout << "Square: " << this->S << ", " << "perimeter: " << this->P << endl;
}

float figure::calc_s(float x1, float x2, float y1, float y2) {
	double f = pow(x2 - x1, 2) + pow(y2 - y1, 2);

	return sqrtf(f);
}

bool figure::is_prug() {
	return (s1 == s3 && s2 == s4 && d1 == d2);
}

bool figure::is_square() {
	return (s1 == s2 && is_prug());
}

bool figure::is_romb() {
	return (s1 == s2 == s3 == s4 && !is_square());
}

bool figure::is_in_circle() {
	float half_p = P / 2;
	float square = sqrt(half_p * (half_p - s1) * (half_p - s2) * (half_p - s3) * (half_p - s4));

	return (S == square);
}

bool figure::is_out_circle() {
	return (s1 + s3 == s2 + s4);
}