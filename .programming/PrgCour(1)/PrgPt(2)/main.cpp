#include "circle.h"

#include <iostream>

using namespace std;

int main()
{
    circle circles[3]{
        circle(0, 0, 0),
        circle(0, 0, 0),
        circle(0, 0, 0)
    };

    float r, x_cntr, y_cntr;

    for (int i = 0; i < 3; i++) {
        cout << "Enter radius of the circle #" << i + 1 << " and coords of its center (X;Y) separated by space: ";

        cin >> r >> x_cntr >> y_cntr;

        circles[i].set_circle(r, x_cntr, y_cntr);
    }

    for (int i = 0; i < 3; i++) {
        circles[i].show();

        float a, b, c;

        cout << "Please, enter sides ABC for triangle which could be in/out of circle #" << i + 1 << " separated by space:";
        
        cin >> a >> b >> c;

        cout << "[CIRCLE] Can given triangle be in/out (answers divided by splash): " << circles[i].triangle_in(a, b, c) << "/" << circles[i].triangle_around(a, b, c) << ";" << endl;

        float rn, xn_cntr, yn_cntr;

        cout << "Please, enter the data for circle, which could be intersected with current circle: ";

        cin >> rn >> xn_cntr >> yn_cntr;

        cout << "[CIRCLE] Is given circle intersected with current: " << circles[i].check_circle(rn, xn_cntr, yn_cntr) << ";" << endl;
    }
}
 