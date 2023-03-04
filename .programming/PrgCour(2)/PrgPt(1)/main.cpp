#include <iostream>

#include "eq2.h"
using namespace std;

int main()
{
    double a, b, c;

    eq2 equations[3];

    for (int i = 0; i < 3; i++) {
        cout << "Type A, B, C for Ax^2 + Bx + C separated by space: ";

        cin >> a >> b >> c;

        equations[i].set(a, b, c);
    }

    for (int i = 0; i < 3; i++) {
        cout << "Type X0 to find Y in this equation #" << i+1 << ":";

        double x0;
        cin >> x0;

        equations[i].find_X();
        cout << "[ANSWER] Y for this equation's params: " << equations[i].find_Y(x0) << endl;
    }

    cout << "There are two equations: " << endl << "1. 2x^2 - 4x + 1 = 0" << endl << "2. 4x^2 - x = 0" << endl;

    eq2 eq0 = eq2(2, -4, 1),
        eq1 = eq2(4, -1, 0);

    eq2 res = eq0 + eq1;

    cout << "[ANSWER] Sum of this two (A1 + A2, B1 + B2 and etc.): " << res.a << ", " << res.b << ", " << res.c << ";" << endl;
}
