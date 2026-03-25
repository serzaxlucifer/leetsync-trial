class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return false;
        }

        int rows = grid.size(), cols = grid[0].size();

        vector<long long> horizontalCuts(grid.size() - 1, 0);
        vector<long long> verticalCuts(grid[0].size() - 1, 0);
        long long totalSum = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                totalSum += grid[i][j];
                if (i < rows - 1) {
                    horizontalCuts[i] += grid[i][j];
                }
                if (j < cols - 1) {
                    verticalCuts[j] += grid[i][j];
                }
            }
        }

        for (int i = 0; i < rows - 1; i++) {
            if (i > 0) {
                horizontalCuts[i] += horizontalCuts[i - 1];
            }
            if (horizontalCuts[i] == totalSum - horizontalCuts[i]) {
                return true;
            }
        }

        for (int i = 0; i < cols - 1; i++) {
            if (i > 0) {
                verticalCuts[i] += verticalCuts[i - 1];
            }
            if (verticalCuts[i] == totalSum - verticalCuts[i]) {
                return true;
            }
        }

        return false;
        
    }
};