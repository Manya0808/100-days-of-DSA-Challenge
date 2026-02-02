int maxProfit(int* prices, int Size) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < Size; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    } 

    return maxProfit;
}


}

