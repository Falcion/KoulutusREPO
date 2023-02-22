#include <iostream>

#include "figure.h"

using namespace std;

int main()
{
    figure figures[3]{
        figure(0, 0, 0, 0, 0, 0, 0, 0),
        figure(0, 0, 0, 0, 0, 0, 0, 0),
        figure(0, 0, 0, 0, 0, 0, 0, 0)
    };

    float x1, x2, x3, x4;
    float y1, y2, y3, y4;

    for (int i = 0; i < 1; i++) {
        cout << "Type (x1, y1), (x2, y2), (x3, y3), (x4, y4) for figure #" << i + 1 << " separated by space: " << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        figures[i] = figure(x1, x2, x3, x4, y1, y2, y3, y4);
    }

    for (int i = 0; i < 1; i++) {
        figures[i].show();

        cout << "Is in circle:" << figures[i].is_in_circle() << ", " << "Is out circle:" << figures[i].is_out_circle() << endl;
        cout << "Is prug: " << figures[i].is_prug() << ", " << "Is romb: " << figures[i].is_romb() << ", " << "Is square: " << figures[i].is_square() << endl;
    }
}