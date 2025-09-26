class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() && nums[i] != 0; j++) {
                while(k < nums.size() && nums[j] + nums[i] > nums[k]) {
                    k++;
                }
                answer += (k - j - 1);
            }
        }

        return answer;
    }
};