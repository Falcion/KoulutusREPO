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

    float r, x, y;

    for (int i = 0; i < 3; i++) {
        cout << "Enter radius of the circle #" << i + 1 << " and coords of its center (X;Y) separated by space: ";

        cin >> r >> x >> y;

        circles[i].set_circle(r, x, y);
    }

    for (int i = 0; i < 3; i++) {
        cout << "[CIRCLE] Square of circle #" << i+1 << ": " << circles[i].square() << ";" << endl;
        
        float a, b, c;

        cout << "Please, enter sides ABC for triangle which could be in/out of circle #" << i + 1 << " separated by space:";
        
        cin >> a >> b >> c;

        cout << "[CIRCLE] Can given triangle be in/out (answers divided by splash): " << circles[i].triangle_in(a, b, c) << "/" << circles[i].triangle_around(a, b, c) << ";" << endl;

        float r1, x1, y1;

        cout << "Please, enter the data for circle, which could be intersected with current circle: ";

        cin >> r1 >> x1 >> y1;

        cout << "[CIRCLE] Is given circle intersected with current: " << circles[i].check_circle(r1, x1, y1) << ";" << endl;
    }
}
 