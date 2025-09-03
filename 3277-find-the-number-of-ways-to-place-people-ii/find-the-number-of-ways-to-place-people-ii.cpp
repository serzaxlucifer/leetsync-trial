class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1];  
            return a[0] < b[0];     
        });
        int numPairs = 0;

        for (int i = 0; i < points.size(); i++) {
            
            int aliceX = points[i][0];
            int aliceY = points[i][1];
            int insideY = -1e9 -1;
            //cout << aliceX << "AliceY: " << aliceY << endl;
            //cout << endl;

            for(int j = i + 1; j < points.size(); j++) {
                int bobX = points[j][0];
                int bobY = points[j][1];
                //cout << bobX << "BobY: " << bobY << endl;

                if (bobY > aliceY) continue;        //  breaks placement constraints
                if (insideY >= bobY) continue;
                //cout << "INCREMENTING" << endl;
                numPairs++;
                insideY = aliceY - bobY < aliceY - insideY ? bobY : insideY;
            }
        }

        return numPairs;
    }
};