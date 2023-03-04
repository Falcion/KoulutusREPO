#include <iostream>

#include "rational.h"
#include <vector>

using namespace std;

int main()
{
    vector<rational> rts;

    int n;

    cout << "[INPUT] Type number of rationals you want to see: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        
        cout << "[INPUT] Type A and B in rational of A/B (separated by space): ";
        cin >> a >> b;

        rts.push_back(rational(a, b));
    }

    for (int i = 0; i < n; i++) {

        rts[i].show();

        int a1, b1;

        cout << "[INPUT] Type A1 and B1 for future operations on A/B: ";

        cin >> a1 >> b1;

        rational r0 = rational(a1, b1);

        rational res = rts[i] + r0;

        cout << "[] Sum between rational #" << i + 1 << " and given: " << res.a << "/" << res.b << ";" << endl;

        res = rts[i] - r0;

        cout << "[] Difference between rational #" << i+1 << " and given: " << res.a << " / " << res.b << "; " << endl;

        res = rts[i]++;

        cout << "[] Increment of rational #" << i+1 << ": " << res.a << "/" << res.b << ";" << endl;

        cout << "[] Rational #" << i + 1 << " is equals to given? " << (r0 == rts[i]) << ";" << endl;
        cout << "[] Rational #" << i+1 << " is bigger than given? " << (r0 > rts[i]) << ";" << endl;
    }
}
