int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int i;
    int diff;
    for (i = 1; i < pricesSize; i++) {
        diff = prices[i] - prices[i - 1];
        if (0 < diff) {
            profit += diff;
        }
    }   
    return profit;
}