/* 
TIME LIMIT EXCEEDED O(n^3)

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
*/

int max(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        return c;
    } else {
        if (b > c) {
            return b;
        }
        return c;
    }
}

int maxProfit(int* prices, int pricesSize) {
    int *buy;
    int *sell;
    int *rest;
    int i;
    buy = (int*)malloc(pricesSize * sizeof(int));
    sell = (int*)malloc(pricesSize * sizeof(int));
    rest = (int*)malloc(pricesSize * sizeof(int));
    for (i = 0; i < pricesSize; i++) {
        buy[i] = 0;
        sell[i] = 0;
        rest[i] = 0;
    }
    buy[0] = 0 - prices[0];
    for (i = 1; i < pricesSize; i++) {
        rest[i] = max(rest[i - 1], sell[i - 1], buy[i - 1]);
        buy[i] = max(buy[i - 1], rest[i - 1] - prices[i], INT_MIN);
        sell[i] = max(rest[i - 1], buy[i - 1] + prices[i], INT_MIN);
    }
    return max(rest[pricesSize - 1], sell[pricesSize - 1], INT_MIN);
}