class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int lastZero = -1;
        int windowStart = 0;
        int maxLen = 0;
        int end = 0;
        bool allOnes = true;

        while(end < nums.size()) {
            if (nums[end] == 0) {
                windowStart = lastZero + 1;
                lastZero = end;
                allOnes = false;
            } else {
                maxLen = max(maxLen, (windowStart <= lastZero && end >= lastZero ) ? end - windowStart : end - windowStart + 1);
            }
            end++;
        }

        return allOnes ? nums.size() - 1 : maxLen;
    }
};