#include <stdio.h>

// int mySqrt(int x) {
//     int i = 0;
//     while (((i + 1) * (i + 1) <= x) && ((i + 1) * (i + 1) > i * i)){
//         i += 1;
//     }
//     return i;
// }

int mySqrt(int x)
{
    long g = x;
    while(g * g > x)
        g = (g + x / g) / 2;
    return g; 
}

int main() {
    int x = 1579205274;
    x = mySqrt(x);
    return 0;
}