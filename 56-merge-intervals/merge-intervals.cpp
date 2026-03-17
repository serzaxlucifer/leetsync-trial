class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());

        int curL = intervals[0][0];
        int curR = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > curR) {
                // no overlap
                answer.push_back({curL, curR});
                curL = intervals[i][0];
                curR = intervals[i][1];
            } else {
                // overlap → merge
                curR = max(curR, intervals[i][1]);
            }
        }

        answer.push_back({curL, curR});
        return answer;
    }
};