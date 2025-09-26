class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Find the number foward just not greater than nums[j]
                int left = j + 1;
                int right = nums.size() - 1;
                int validCount = 0;
                
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[i] + nums[j] > nums[mid]) {
                        validCount = mid - j; // All elements from j+1 to mid are valid
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                
                answer += validCount;
            }
        }

        return answer;
    }
};