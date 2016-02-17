#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i = 0;
    int now = 0;
    int not_complete = 1;
    int edge = numsSize - 1;
    if (0 == numsSize)
    {
        not_complete = 0;
    }
    while (not_complete)
    {
        nums[i] = nums[now];
        i += 1;
        while ((nums[now] == nums[now + 1]) && (now < edge))
        {
            now += 1;
        }
        now += 1;
        if (numsSize == now)
        {
            not_complete = 0;
        }
    }
    return i;
}

int main()
{
    int nums[] = {1, 2, 2, 3, 4, 5, 5, 5};
    int numsSize = 8;
    int number;
    number = removeDuplicates(nums, numsSize);
    printf("%d\n", number);
    while (number > 0)
    {
        printf("%d ", nums[number - 1]);
        number -= 1;
    }
    return 0;
}
