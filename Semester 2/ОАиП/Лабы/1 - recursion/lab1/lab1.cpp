#include <iostream>

int fibonacciRec(int n) {
    if (n == 0) return 0; // Fb(0) = 0
    if (n == 1) return 1; // Fb(1) = 1
    return fibonacciRec(n - 1) + fibonacciRec(n - 2); // Fb(n) = Fb(n-1) + Fb(n-2)
}

int fibonacciIter(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // prev for storing Fb(n-1), prev2 for Fb(n-2)
    int res = 0, prev = 0, prev2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 1) {
            res += 1;
            prev2 = 1;
        }
        else {
            // next for next number, then update previous numbers
            int next = prev + prev2;
            res += next;
            prev2 = prev;
            prev = next;
        }
    }
    return res;
}


int main()
{
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181
    const int MIN = 0, MAX = 19;

    for (int i = MIN; i <= MAX; i++)
    {
        std::cout << "Fb(" << i << ") = " << std::endl;
        std::cout << fibonacciRec(i) << " recursively" << std::endl;
        std::cout << fibonacciIter(i) << " iteratively" << std::endl;
        std::cout << std::endl;
    }
}