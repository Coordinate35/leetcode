#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maxArea(int* height, int heightSize)
{
    int max_area, i, j, current_area;
    max_area = 0;
    i = 0;
    j = heightSize - 1;
    while (j > i)
    {
        current_area = min(height[i], height[j]) * (j - i);
        max_area = max(current_area ,max_area);
        if (height[i] > height[j])
        {
            j -= 1;
        }
        else
        {
            i += 1;
        }
    }
    return max_area;
}

int main()
{
    int heightSize, max_area;
    int height[] = {1, 1};
    heightSize = 2;
    max_area = maxArea(height, heightSize);
    printf("%d\n", max_area);
    return 0;
}
