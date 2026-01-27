class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = INT_MAX;

        for(int i = 0; i < nums.size() - k + 1; i++) {
            answer = min(answer, nums[i + k - 1] - nums[i]);
        }

        return answer;
    }
};