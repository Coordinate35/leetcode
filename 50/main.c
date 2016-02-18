#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n)
{
    double result = 1;
    if (0 > n)
    {
        n = (-1) * n;
        x = 1 / x;
    }
    while (n != 0)
    {
        if (0 != n % 2)
        {
            result *= x;
        }
        x = x * x;
        n /= 2;
    }
    return result;
}

int main()
{
    double x = 8.88023;
    int n = 3;
    double result;
    result = myPow(x, n);
    printf("%lf\n", result);
    return 0;
}
