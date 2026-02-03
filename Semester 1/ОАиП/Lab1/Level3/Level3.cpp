#include <iostream>

using namespace std;

static void tryAgain() {
    cout << "Try again." << endl;
    cin.clear();
    cin.ignore(10000, '\n');
}

int main()
{
    double x, y, z, beta;

    while (1) {
        cout << "Enter a value for x: ";
        cin >> x;
        cout << "Enter a value for y: ";
        cin >> y;
        cout << "Enter a value for z: ";
        cin >> z;

        if (!cin.good()) {
            cout << endl << "Wrong input!" << endl;
            tryAgain();
            continue;
        }

        if (z - fabs(x - y) > 1 || z - fabs(x - y) < -1) {
            cout << "Cant calc arcsin of a num bigger than 1 / less than -1" << endl;
            tryAgain();
            continue;
            
        }
        if (10. * (cbrt(x) + pow(x, y + 2)) < 0) {
            cout << "Number under the square root is less than 0" << endl;
            tryAgain();
            continue;
        }

        beta = sqrt(10. * (cbrt(x) + pow(x, y + 2))) * (pow(asin(z - fabs(x - y)), 2));

        cout << beta << endl;
        break;
    }
}