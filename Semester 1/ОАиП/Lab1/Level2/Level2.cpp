#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a, z1, z2;
    bool isValid = false;

    while (!isValid) {
        cout << "Enter alpha: ";
        cin >> a;
        bool isGood = cin.good();
        if (isGood) {
            if (a <= 0 || (pow((3. * a + 2.), 2) - 24. * a) < 0 || (3. * sqrt(a) - 2. / sqrt(a)) == 0) {
                cout << "Division by zero / square root of a negative number" << endl;
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

    z1 = sqrt(pow((3. * a + 2.), 2) - 24. * a) / (3. * sqrt(a) - 2. / sqrt(a));
    z2 = sqrt(a);

    std::cout << "Calulated value of z1: " << z1 << "\n";
    std::cout << "Calulated value of z2: " << z2 << "\n";
}