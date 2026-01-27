class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;

        for (int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, abs(arr[i] - arr[i + 1]));
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] - arr[i + 1] == minDiff) {
                answer.push_back({arr[i + 1], arr[i]});
            }

            if (arr[i + 1] - arr[i] == minDiff) {
                answer.push_back({arr[i], arr[i + 1]});
            }
        }

        return answer;
    }
};