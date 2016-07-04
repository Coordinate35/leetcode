bool canJump(int* nums, int numsSize) {
    int current = 0;
    int last = 0;   
    int i;
    for (i = 0; i < numsSize; i++) {
        if (i > current) {
            return false;
        }
        if (current < nums[i] + i) {
            current = nums[i] + i;
        }
        if (current >= numsSize - 1) {
            return true;
        }
    }
    return true; 
}