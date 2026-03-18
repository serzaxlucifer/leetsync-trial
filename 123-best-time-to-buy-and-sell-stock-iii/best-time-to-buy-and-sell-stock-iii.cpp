class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(prices.size(), -1)));
        
        // for (int i = 0; i < prices.size(); i++) {
        //     int stockPrice = prices[i];

        //     // If this is the first transaction
        //     if (dp[0][i - 1])
        // }

        return findMax(prices, 0, 2, true, dp);
    }

    int findMax(vector<int>& prices, int cur, int cap, bool buy, vector<vector<vector<int>>>& dp) {
        if (cur == prices.size()) {
            return 0;
        }
        if (cap == 0) {
            return 0;
        }

        int dpIndex = buy ? 1 : 0;

        if (dp[cap-1][dpIndex][cur] != -1) {
            return dp[cap-1][dpIndex][cur];
        }
        
        int profit = 0;

        if (buy) {
            profit = max(findMax(prices, cur + 1, cap, false, dp) -  prices[cur], findMax(prices, cur + 1, cap, true, dp));
        } else {
            profit = max(prices[cur] + findMax(prices, cur + 1, cap - 1, true, dp), findMax(prices, cur + 1, cap, false, dp));
        }

        return dp[cap-1][dpIndex][cur] = profit;
    }
};