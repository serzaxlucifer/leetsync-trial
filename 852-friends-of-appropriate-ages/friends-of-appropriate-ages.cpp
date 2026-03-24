class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int answer = 0;
        int leftPtr = 0, rightPtr = 0;

        for (int i = 0; i < ages.size(); i++) {
            int curAge = ages[i];
            if (curAge <= 14) continue;

            while (ages[leftPtr] <= 0.5*curAge + 7) leftPtr++;
            while (rightPtr + 1 < ages.size() && ages[rightPtr + 1] <= ages[i]) rightPtr++;

            answer += (rightPtr - leftPtr);
        }

        return answer;
    }
};