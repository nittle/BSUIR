#include <iostream>
#include <cmath>

int main()
{
    double a, z1, z2;
    std::cout << "Enter a value for alpha: ";
    std::cin >> a;

    z1 = cos(a) + cos(2. * a) + cos(6. * a) + cos(7. * a);
    z2 = 4. * cos(a / 2.) * cos(5. / 2. * a) * cos(4. * a);

    std::cout << "Computed value of z1 = " << z1 << "\n";
    std::cout << "Computed value of z2 = " << z2 << "\n";
    return 0;
}