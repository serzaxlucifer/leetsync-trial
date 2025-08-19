class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0;
        int windowStart = 0;
        int windowEnd = 0;

        while(windowEnd < nums.size()) {
            if (nums[windowEnd] == 0) {
                ans += (windowEnd - windowStart + 1);
                windowEnd++;
            } else {
                windowEnd++;
                windowStart = windowEnd;
            }
        }

        return ans;
    }
};