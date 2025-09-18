class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        // Forming a subsequence, we arrive at a character. We have
        // 2 options: Include it or exclude it.

        int length = s.length();
        int dp[26] = {0};
        int maxLen = 0;

        for(int i = 0; i < length; i++) {
            char a = s[i];
            for(int j = max(0, a - 'a' - k); j <= min(25, a - 'a' + k); j++) {
                dp[a - 'a'] = max(dp[a - 'a'], dp[j]);
            }
            dp[a - 'a']++;
            maxLen = max(maxLen, dp[a - 'a']);
        }

        return maxLen;
    }
};