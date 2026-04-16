class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> lookup;
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++) {
            lookup[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            int element = nums[queries[i]];

            if (lookup.find(element) == lookup.end() || lookup[element].size() == 1) {
                answer.push_back(-1);
                continue;
            }

            answer.push_back(findMinIndexDistanct(lookup[element], queries[i], nums.size() - 1));
        }

        return answer;
    }

    int findMinIndexDistanct(vector<int>& indices, int index, int size) {
        int minVal = INT_MAX;
        int lastIndex = indices[indices.size() - 1];
        int indexInIndices =lower_bound(indices.begin(), indices.end(), index) -indices.begin();
        int prevDistance = INT_MAX, nextDistance = INT_MAX;

        if (indexInIndices == 0) {
            prevDistance = (size - lastIndex + 1) + indices[indexInIndices];
            nextDistance = indices[indexInIndices + 1] - indices[indexInIndices];
        } else if (indexInIndices == indices.size() - 1) {
            prevDistance = indices[indexInIndices] - indices[indexInIndices - 1];
            nextDistance = (size - indices[indexInIndices] + 1) + indices[0];
        } else {
            prevDistance = indices[indexInIndices] - indices[indexInIndices - 1];
            nextDistance = indices[indexInIndices + 1] - indices[indexInIndices];
        }

        return min(prevDistance, nextDistance);
    }
};