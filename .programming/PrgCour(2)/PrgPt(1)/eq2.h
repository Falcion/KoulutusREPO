class eq2 {
public:
	double a, b, c;
	double D;
	eq2();
	eq2(double a1, double b1, double c1);
	void set(double a1, double b1, double c1);
	double find_X();
	double find_Y(double x1);
	friend eq2 operator+(eq2 eq0, eq2 eq1);
};