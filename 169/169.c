// void quick_sort(int* nums, int l, int r) {
//     int privot = nums[l];
//     int i, j;
//     int temp;
//     j = l;
//     if (l < r) {
//         for (i = l; i <= r; i++) {
//             if (nums[i] < privot) {
//                 temp = nums[j];
//                 nums[j] = nums[i];
//                 nums[i] = nums[j + 1];
//                 nums[j + 1] = temp;
//                 j += 1;
//             }
//         }
//         quick_sort(nums, l, j - 1);
//         quick_sort(nums, j + 1, r);
//     }
// }

// int majorityElement(int* nums, int numsSize) {
//     quick_sort(nums, 0, numsSize - 1);
//     return nums[numsSize / 2];   
// }

int majorityElement(int* nums, int numsSize) {
    int i, count = 0, majority_element;
    for (i = 0; i < numsSize; i++) {
        if (0 == count) {
            count += 1;
            majority_element = nums[i];
        } else if (majority_element == nums[i]) {
            count += 1;
        } else {
            count -= 1;
        }
    }
    return majority_element;
}