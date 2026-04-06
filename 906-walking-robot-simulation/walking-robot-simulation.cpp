class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Directions: North, East, South, West (clockwise)
        int directions[4][2] = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        
        unordered_set<long long> obstacleSet;

        // Encode obstacles
        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (o[1] & 0xffffffff);
            obstacleSet.insert(key);
        }

        int dir = 0; // 0 = North
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {

            if (cmd == -1) { // turn right
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) { // turn left
                dir = (dir + 3) % 4; // same as (dir - 1 + 4) % 4
            } 
            else {
                for (int step = 0; step < cmd; step++) {

                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];

                    long long key = ((long long)nx << 32) | (ny & 0xffffffff);

                    // Stop if obstacle
                    if (obstacleSet.count(key)) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};