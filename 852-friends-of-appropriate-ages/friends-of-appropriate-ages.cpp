class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int map[121] = {0};
        for (int i : ages) {
            map[i]++;
        }

        vector<int> pref(121, 0);
        for (int i = 1; i <= 120; i++) {
            pref[i] = pref[i - 1] + map[i];
        }

        int answer = 0;

        for(int i = 15; i <= 120; i++) {
            if (map[i] == 0) continue;
            int lb = 0.5*i + 7;
            int rb = i;

            int total = pref[rb] - pref[lb];
            answer += map[i] * (total - 1);
        }


        return answer;
    }
};