int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int maxProfit(int* prices, int pricesSize) {
    int *f, *g;
    int i;
    int current_min = prices[0], current_max = prices[pricesSize - 1];
    int profit = 0;
    f = (int*)malloc(pricesSize * sizeof(int));
    g = (int*)malloc(pricesSize * sizeof(int));
    f[0] = 0;
    g[pricesSize - 1] = 0;

    for (i = 1; i < pricesSize; i++) {
        current_min = min(prices[i], current_min);
        f[i] = max(f[i - 1], prices[i] - current_min);
    }

    for (i = pricesSize - 2; i >= 0; i--) {
        current_max = max(prices[i], current_max);
        g[i] = max(g[i + 1], current_max - prices[i]);
    }

    for (i = 0; i < pricesSize; i++) {
        if (profit < f[i] + g[i]) {
            profit = f[i] + g[i];
        }
    }
    return profit;
}