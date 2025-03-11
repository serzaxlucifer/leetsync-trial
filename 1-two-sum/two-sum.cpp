class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hello 
        vector<int> result;
        int diff;
        unordered_map<int, int> mymap;

        for (int i = 0; i < nums.size(); i++) 
        {
            diff = target - nums[i];
            if (mymap.find(diff) != mymap.end()) 
            {
                result.push_back((mymap.find(diff))->second);
                result.push_back(i);
                return result;
            }
            mymap[nums[i]] = i;
        }
        return result;
    }
};