int maxSubArray(int* nums, int numsSize) {
    int i;
    int result = INT_MIN;
    int max_sub_sum = -1;
    for (i = 0; i < numsSize; i++) {
        if (0 > max_sub_sum) {
            max_sub_sum = nums[i];
        } else {
            max_sub_sum += nums[i];
        }
        if (max_sub_sum > result) {
            result = max_sub_sum;
        }
    }   
    return result;
}