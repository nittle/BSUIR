#include <iostream>

using namespace std;

float phi(int choice, float input) {
    switch (choice) 
    {
    case 1:
        cout << "phi is 2*x" << endl;
        return 2 * input;
    case 2:
        cout << "phi is x^2" << endl;
        return powf(input, 2);
    case 3:
        cout << "phi is x/3" << endl;
        return input / 3;
    default:
        cout << "returning x" << endl;
        return input;
        //break;
    }
}

int main()
{
    float x, y, z, a, b;
    int phiChoice;
    bool isValid = false;

    while (!isValid) {
        cout << "Enter z: ";
        cin >> z;
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;

        if (z < -1) {
            cout << "z < -1 then x = -z / 3" << endl;
            x = -z / 3;
        }
        else if (z >= -1) {
            cout << "z >= -1 then x = |z|" << endl;
            x = fabs(z);
        }

        bool isGood = cin.good();
        if (isGood) {
            if (x + 2.5 < 0) {
                cout << "Out of boundaries" << endl;
                cout << "Try entering a different number: ";
            }
            else {
                isValid = true;
            }
        }
        else {
            cout << "Input incorrect. Try again." << endl;
        }
        cin.clear();
        cin.ignore(100000, '\n');
    }

    cout << "x = " << x << endl;

    isValid = false;

    while (!isValid) {
        cout << "Choose phi(1 - 2x, 2 - x^2, 3 - x/3): ";
        cin >> phiChoice;
        bool isGood = cin.good();
        if (isGood) {
            //if (phiChoice > 3 || phiChoice < 1) {
            //    cout << "Wrong choice(choose 1-3): " << endl;
            //}
            //else {
            //    isValid = true;
            //}
            isValid = true;
        }
        else {
            cout << "Input incorrect. Try again." << endl;
        }
        cin.clear();
        cin.ignore(100000, '\n');
    }

    y = a * phi(phiChoice, x) - log(x + 2.5) + b * (exp(x) - exp(-x));
    
    cout << "Calculated value of y: " << y;

    return 0;
}