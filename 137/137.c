int singleNumber(int* nums, int numsSize) {
    int one = 0;
    int two = 0;
    int three = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        two |= (one & nums[i]);
        one ^= nums[i];
        three = ~ (one & two);
        one &= three;
        two &= three;
    }   
    return one;
}