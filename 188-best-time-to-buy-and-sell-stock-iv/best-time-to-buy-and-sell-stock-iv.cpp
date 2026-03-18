class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int i : prices) {
            for (int j = 1; j <= k; j++) {
                // Buy
                buy[j] = max(buy[j], sell[j - 1] - i);

                // Sell
                sell[j] = max(sell[j], buy[j] + i);
            }
        }

        return sell[k];
    }
};