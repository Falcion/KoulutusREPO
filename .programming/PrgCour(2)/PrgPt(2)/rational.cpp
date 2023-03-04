#include <iostream>
#include <numeric>

#include "rational.h"

using namespace std;

rational::rational() {
	a = 0;
	b = -1;
}

rational::rational(int a1, int b1) {
	a = a1;
	b = b1;

	if (b == 0) {
		cout << "Divisor is equals zero!" << endl;
		return;
	}

	int _gcd = gcd(abs(a1), abs(b1));

	a /= _gcd;
	b /= _gcd;

	if (b < 0) {
		b *= -1;
		a *= -1;
	}
}

void rational::set(int a1, int b1) {
	a = a1;
	b = b1;

	if (b == 0) {
		cout << "Divisor is equals zero!" << endl;
		return;
	}

	int _gcd = gcd(abs(a1), abs(b1));

	a /= _gcd;
	b /= _gcd;

	if (b < 0) {
		b *= -1;
		a *= -1;
	}
}

void rational::setrt(int a1, int b1) {
	a = a1;
	b = b1;

	if (b == 0) {
		cout << "Divisor is equals zero!" << endl;
		return;
	}
}

int rational::gcd(int a1, int b1) {
	if (b1 == 0)
		return a1;
	return gcd(b1, a1 % b1);
}

void rational::show() {
	cout << a << "/" << b << endl;
}

rational rational::operator+(rational r) {
	rational rat;

	int tempB = b;
	
	this->setrt(a * r.b, b * r.b);
	r.setrt(r.a * tempB, r.b * tempB);

	rat.set(this->a + r.a, this->b);

	return rat;
}

rational operator-(rational r0, rational r1) {
	rational rat;

	int tempB = r0.b;

	r0.setrt(r0.a * r1.b, r0.b * r1.b);
	r1.setrt(r1.a * tempB, r1.b * tempB);

	rat.set(r0.a - r1.a, r0.b);

	return rat;
}

/* INCREMENT AND OPERATIONS WITH RATIONALS WORKS WITH
*  PARSED NUMBERS, IT MEANS, THAT IT CAN TRANSFORM:
*  1/3 -> 8/6 and etc. (8/6 is equals to 4/3 which is 1/3 + 1);
*  This happens because of an array of methods which work with rational
*/

rational rational::operator++() {
	rational temp;
	temp.setrt(a + b, b);
	return temp;
}

rational rational::operator++(int) {
	rational temp;
	temp.setrt(a + b, b);
	return temp;
}

bool rational::operator==(rational r) {
	rational temp;

	temp.setrt(this->a, this->b);

	return (this->a == temp.a && this->b == temp.b);
}

bool rational::operator>(rational r) {
	rational rat;

	int tempB = b;

	this->setrt(a * r.b, b * r.b);
	r.setrt(r.a * tempB, r.b * tempB);

	rat.set(this->a + r.a, this->b);

	return (this->a > r.a);
}

void rational::operator=(rational r) {
	this->setrt(r.a, r.b);
}