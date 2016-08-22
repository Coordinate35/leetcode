int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int maxProfit(int* prices, int pricesSize) {
    int current_min = prices[0];
    int i;
    int max_profix = 0;
    for (i = 1; i < pricesSize; i++) {
        max_profix = max(max_profix, prices[i] - current_min);
        current_min = min(current_min, prices[i]);
    }   
    return max_profix;
}