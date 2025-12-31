class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(canCross(row, col, cells, mid)) {
                ans = mid;         // we can cross on mid
                left = mid + 1;    // try later day
            } else {
                right = mid - 1;   // try earlier day
            }
        }
        return ans;
    }

    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood first 'day' cells as water (1)
        for(int i = 0; i < day; i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;

        queue<pair<int,int>> q;

        // Push all land cells in top row into BFS
        for(int j = 0; j < col; j++) {
            if(grid[0][j] == 0) {
                q.push({0,j});
                grid[0][j] = -1; // mark visited
            }
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();

            if(r == row-1) return true; // reached bottom row

            for(auto &d: dir) {
                int nr = r + d[0], nc = c + d[1];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    grid[nr][nc] = -1;   // mark visited
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
};
