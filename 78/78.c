/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int i, j;
    int presize, current_size, prelength;
    int **sub_sets;
    int **pre_sub_sets;
    int *temp_set;
    if (0 == numsSize) {
        sub_sets = (int**)malloc(sizeof(int*));
        sub_sets[0] = NULL;
        (*columnSizes) = (int*)malloc(sizeof(int));
        (*columnSizes)[0] = 0;
        *returnSize = 1;
        return sub_sets;
    }

    pre_sub_sets = subsets(nums, numsSize - 1, columnSizes, returnSize);
    presize = (*returnSize);
    (*returnSize) *= 2;
    current_size = (*returnSize);
    sub_sets = (int**)realloc(pre_sub_sets, current_size * sizeof(int*));
    (*columnSizes) = (int*)realloc((*columnSizes), current_size * sizeof(int));
    for (i = 0; i < presize; i++) {
        prelength = (*columnSizes)[i];
        temp_set = (int*)malloc((prelength + 1) * sizeof(int));
        for (j = 0; j < prelength; j++) {
            temp_set[j] = sub_sets[i][j];
        }
        temp_set[prelength] = nums[numsSize - 1];
        sub_sets[presize + i] = temp_set;
        (*columnSizes)[presize + i] = prelength + 1; 
    }
    return sub_sets;
}