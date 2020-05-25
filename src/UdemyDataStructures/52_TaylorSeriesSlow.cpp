#include <stdio.h>
#include <iostream>

double e(int x, int n) {
    static double p = 1, f = 1;
    double result;

    if (n==0)
        return 1;
    result = e(x, n-1);
    p *= x;
    f *= n;

    return result + p/f;
}

int main() {
    std::cout << e(1,9);
    return 0;
}
