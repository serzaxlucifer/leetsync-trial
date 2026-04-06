class Solution {
public:
    int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(((long long)p.first << 32) | p.second);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int startingIndex = 0;
        int maxDistance = 0;
        int x = 0, y = 0;

        unordered_set<pair<int,int>, pair_hash> obstaclesSet;

        for (auto& i : obstacles) {
            obstaclesSet.insert({i[0], i[1]});
        }

        for (int val : commands) {

            if (val == -1) {
                startingIndex = normalizePt(startingIndex - 1);
                continue;
            } 
            if (val == -2) {
                startingIndex = normalizePt(startingIndex + 1);
                continue;
            }

            for (int m = 0; m < val; m++) {
                auto s = getNextPos(x, y, startingIndex);
                int newX = s[0], newY = s[1];

                if (obstaclesSet.find({newX, newY}) != obstaclesSet.end()) {
                    break;
                }

                x = newX;
                y = newY;

                maxDistance = max(maxDistance, x*x + y*y);
            }
        }

        return maxDistance;
    }

    int normalizePt(int index) {
        if (index == -1) return 3;
        if (index == 4) return 0;
        return index;
    }

    vector<int> getNextPos(int x, int y, int idx) {
        return {x + directions[idx][0], y + directions[idx][1]};
    }
};