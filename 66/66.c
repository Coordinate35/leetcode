/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    *returnSize = digitsSize;
    digits[digitsSize - 1] += 1;
    for (i = digitsSize - 1; i > 0; i--) {
        digits[i - 1] += digits[i] / 10;
        digits[i] = digits[i] % 10;
        if (digits[i - 1] < 10) {
            return digits;
        } 
    }   
    if (digits[0] <= 9) {
        return digits;
    }
    digitsSize += 1;
    *returnSize = digitsSize;
    digits = realloc(digits, digitsSize * sizeof(int));
    for (i = digitsSize - 1; i > 0; i--) {
        digits[i] = digits[i - 1];
    }
    digits[0] = digits[1] / 10;
    digits[1] = digits[1] % 10;
    return digits;
}