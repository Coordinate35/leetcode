int candy(int* ratings, int ratingsSize) 
{
    int *candies = (int*)malloc(ratingsSize * sizeof(int));
    int *compensate = (int*)malloc(ratingsSize * sizeof(int));
    int i;
    int sum = 0;
    int first_compensate = 0;
    if (0 == ratingsSize) {
        return 0;
    }
    if (1 == ratingsSize) {
        return 1;
    }
    candies[0] = 1;
    compensate[0] = 0;
    printf("1 ");
    for (i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
        if (ratings[i] < ratings[i - 1]) {
            compensate[i] = compensate[i - 1] + 1;
        } else {
            compensate[i] = 0;
        }
        sum += candies[i];
        if (((1 == candies[i - 1]) && (1 == candies[i]) && (i + 1 != ratingsSize) && (ratings[i + 1] >= ratings[i])) || ((1 == candies[i - 1]) && (1 == candies[i]) && (i == ratingsSize - 1))) {
            first_compensate = compensate[i] > (candies[i - compensate[i]] - 1) ? compensate[i] + 1 - candies[i - compensate[i]] : 0;
            sum += ((compensate[i] - 1) * compensate[i] / 2) + first_compensate;
        }
        printf("%d ", candies[i]);
    }
    sum += candies[0];
    printf("\n");
    for (i = 0; i < ratingsSize; ++i) {
        printf("%d ", compensate[i]);
    }
    return sum;
}