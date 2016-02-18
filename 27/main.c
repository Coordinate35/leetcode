#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val)
{
    int now = 0, i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            nums[now] = nums[i];
            now += 1;
        }
    }
    return now;
}

int main()
{
    int nums[] = {1, 2, 2, 3, 4, 5, 5, 5};
    int numsSize = 8;
    int val = 2;
    int number;
    number = removeElement(nums, numsSize, val);
    printf("%d\n", number);
    while (number > 0)
    {
        printf("%d ", nums[number - 1]);
        number -= 1;
    }
    return 0;
}
