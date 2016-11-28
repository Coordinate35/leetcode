int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int maxOneTransaction(int* prices, int from, int to) {
    int currentMin = prices[from];
    int i;
    int maxProfit = 0;
    for (i = from; i <= to; i++) {
        if (prices[i] < currentMin) {
            currentMin = prices[i];
        }
        maxProfit = max(maxProfit, prices[i] - currentMin);
    }
    return maxProfit;
}

int maxProfit(int* prices, int pricesSize) {
    int i, j;
    int *f;
    int maxSellTime;
    int maxBuyTime;
    if (1 >= pricesSize) {
        return 0;
    }
    f = (int*)malloc(pricesSize * sizeof(int));
    for (i = 0; i < pricesSize; i++) {
        f[i] = 0;
    }
    for (i = 1; i < pricesSize; i++) {
        if (i == pricesSize - 1) {
            maxSellTime = i;
        } else {
            maxSellTime = i - 1;
        }
        maxBuyTime = maxSellTime - 1;
        f[i] = maxOneTransaction(prices, 0, maxSellTime);
        for (j = 0; j < maxBuyTime; j++) {
            f[i] = max(f[i], f[j] + maxOneTransaction(prices, j + 1, maxSellTime));
        }
    }
    return f[pricesSize - 1];
}