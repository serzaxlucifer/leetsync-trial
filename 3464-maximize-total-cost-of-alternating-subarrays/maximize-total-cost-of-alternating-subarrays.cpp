class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long prevPos = nums[0];
        long long prevNeg = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            long long oldNeg = prevNeg;
            prevNeg = prevPos - nums[i];
            prevPos = max(oldNeg + nums[i], prevPos + nums[i]);
        }
        return max(prevPos, prevNeg);
        
    }
};