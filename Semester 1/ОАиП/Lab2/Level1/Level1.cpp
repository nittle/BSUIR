#include <iostream>

using namespace std;
int main()
{
    const float E = 2.71828;
    float x, y, z;

    cout << "Input z: ";

    cin >> z;

    if (z < -1) {
        x = -z / 3;
        cout << "z < -1 then x = -z / 3 = " << x << endl;
    }
    else if (z >= -1) {
        x = z + log(z);
        cout << "z >= -1 then x = z + log(z) = " << x << endl;
    }
    else {
        cout << "Wrong input" << endl;
        return 0;
    }

    y = log(x + 0.5) + (pow(E, x) - pow(E, -x));

    cout << "Calculated value of y: " << y << endl;
}