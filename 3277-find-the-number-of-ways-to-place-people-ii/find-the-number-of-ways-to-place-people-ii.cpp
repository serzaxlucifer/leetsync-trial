class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, {}, [](auto &p){ return pair(p[0], -p[1]);});
        int numPairs = 0;

        for (int i = 0; i < points.size(); i++) {
            
            int aliceX = points[i][0];
            int aliceY = points[i][1];
            int insideY = -1e9 -1;

            for(int j = i + 1; j < points.size(); j++) {
                int bobX = points[j][0];
                int bobY = points[j][1];

                if (bobY > aliceY || insideY >= bobY) continue;
                numPairs++;

                insideY = aliceY - bobY < aliceY - insideY ? bobY : insideY;
            }
        }

        return numPairs;
    }
};