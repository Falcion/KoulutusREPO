#include "triangle.h"

#include <iostream>

using namespace std;

int main()
{
    triangle triangles[3];

    double a;
    double b;
    double c;

    for (int i = 0; i < 3; i++) {
        cout << "Enter three sides length for triangle #" << i + 1 << " separated by space: ";

        cin >> a >> b >> c;

        triangles[i].set(a, b, c);

        if (!triangles[i].exst_tr()) {
            triangles[i].show();

            cout << "This triangle doesn't exist, please, try again!" << endl;

            i--;
        }
    }

    for (int i = 0; i < 3; i++) {
        triangles[i].show();

        cout << "[TRIANGLE] Perimeter (#" << i + 1 << "): " << triangles[i].perimeter() << ";" << endl;
        cout << "[TRIANGLE] Square (#" << i + 1 << "): " << triangles[i].square() << ";" << endl;
    }
}
