class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(3, vector<int>(2, 0)), cur(3, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int cap = 1; cap <= 2; cap++) {
                // buy = 1
                cur[cap][1] = max(-prices[i] + ahead[cap][0], ahead[cap][1]);

                // buy = 0
                cur[cap][0] = max(prices[i] + ahead[cap-1][1], ahead[cap][0]);
            }
            ahead = cur;
        }

        return ahead[2][1];
    }
};