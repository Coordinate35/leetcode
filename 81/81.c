void find_right_part_start(int* nums, int start, int end, int* right_part_start) {
    int middle = (start + end) / 2;
    if (start >= end) {
        return;
    }
    if (middle > start) {
        if (nums[middle] < nums[middle - 1]) {
            *right_part_start = middle;
        }
    }
    if (middle < end) {
        if (nums[middle] > nums[middle + 1]) {
            *right_part_start = middle + 1;
        }
    }
    find_right_part_start(nums, middle + 1, end, right_part_start);
    find_right_part_start(nums, start, middle - 1, right_part_start);
}

void search_certain_value(int* nums, int start, int end, bool* result, int target) {
    int middle = (start + end) / 2;
    if (start > end) {
        return;
    }
    if (target == nums[middle]) {
        *result = true;
    }
    search_certain_value(nums, start, middle - 1, result, target);
    search_certain_value(nums, middle + 1, end, result, target);
}

bool search(int* nums, int numsSize, int target) {
    int right_part_start = 0;
    bool result = false;
    find_right_part_start(nums, 0, numsSize - 1, &right_part_start);
    search_certain_value(nums, 0, right_part_start - 1, &result, target);
    if (false == result) {
        search_certain_value(nums, right_part_start, numsSize - 1, &result, target);
    }
    return result;
}