class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        // TABULATION

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> dp(triangle.size(), -1);
        int size = triangle.size();

        dp[0] = triangle[0][0];

        for(int i = size - 1; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {

                if(i == size - 1)
                {
                    dp[j] = triangle[i][j];
                }

                else
                {
                    dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
                }
            }
        }

        return dp[0];
    }


};