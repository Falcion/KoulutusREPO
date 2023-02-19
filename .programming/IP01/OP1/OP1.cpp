#include <iostream>
#include "Triangle.h"
#include "Circle.h"
#include "Figure.h"
#include <vector>

int main()
{
    // Triangle
    Triangle triangles[3];
    double a, b, c;

    for (int i = 0; i < 3; i++) {
        cout << "Type sides A, B, C for triangle #" << i + 1 << " separated by space: " << endl;
        cin >> a >> b >> c;
        triangles[i].set(a, b, c);
        if (!(triangles[i].exst_tr())) {
            triangles[i].show();
            cout << "Triangle with such sides doesn't exist, try again!" << endl;
            i--;
        }
    }

    for (int i = 0; i < 3; i++) {
        triangles[i].show();
        cout << "Triangle's perimeter: " << triangles[i].perimetr() << endl;
        cout << "Triangle's square: " << triangles[i].square() << endl;
    }

    // Circle
    Circle circles[3]{
        Circle(0, 0, 0),
        Circle(0, 0, 0),
        Circle(0, 0, 0)
    };

    float r, x_center, y_center;

    for (int i = 0; i < 3; i++) {
        cout << "Type radius, center's X, center's Y for circle #" << i + 1 << " separated by space: " << endl;
        cin >> r >> x_center >> y_center;
        circles[i].set_circle(r, x_center, y_center);
    }

    for (int i = 0; i < 3; i++) {
        circles[i].show();
        cout << "Circle's square: " << circles[i].square() << endl;

        cout << "Type A, B, C for triangle which is inside/outside of circle #" << i + 1 << " separated by space: " << endl;

        cin >> a >> b >> c;
        cout << "Is ABC inside? " << circles[i].triangle_in(a, b, c) << endl << "Is ABC outside? " << circles[i].triangle_around(a, b, c) << endl;

        float r2, x2, y2;
        cout << "Type context for circle to check, does it crossed between (R, Xc, Yc): " << endl;
        cin >> r2 >> x2 >> y2;
        cout << "Circles are crossing? " << circles[i].check_circle(r2, x2, y2) << endl;
    }

    // Figure
    Figure figures[3]{
        Figure(0, 0, 0, 0, 0, 0, 0, 0),
        Figure(0, 0, 0, 0, 0, 0, 0, 0),
        Figure(0, 0, 0, 0, 0, 0, 0, 0)
    };

    float x1, x2, x3, x4, y1, y2, y3, y4;

    for (int i = 0; i < 3; i++) {
        cout << "Type (x1, y1), (x2, y2), (x3, y3), (x4, y4)" << i + 1 << "separated by space: " << endl;
        cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;

        figures[i] = Figure(x1, x2, x3, x4, y1, y2, y3, y4);
    }

    for (int i = 0; i < 3; i++) {
        figures[i].show();

        cout << "Is in circle:" << figures[i].is_in_circle() << ", " << "Is out circle:" << figures[i].is_out_circle() << endl;
        cout << "Is prug: " << figures[i].is_prug() << ", " << "Is romb: " << ", " << figures[i].is_romb() << ", " << "Is square: " << ", " << figures[i].is_square();
    }
}

