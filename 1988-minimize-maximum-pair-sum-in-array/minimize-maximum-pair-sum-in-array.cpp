class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int minimax = 0;

        while(start < end) {
            int pairSum = nums[start] + nums[end];
            minimax = max(minimax, pairSum);
            start++;
            end--;
        }

        return minimax;
    }
};