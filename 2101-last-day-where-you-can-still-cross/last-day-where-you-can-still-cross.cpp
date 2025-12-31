class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; // row,col

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0, hi = cells.size(), ans = 0;

        while(lo <= hi){
            int mid = (lo + hi) / 2;

            vector<vector<int>> grid(row, vector<int>(col,0));

            for(int i = 0; i < mid; i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1; // mark water correctly
            }

            if(canCross(grid)){
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }

    bool canCross(vector<vector<int>>& grid){
        int col = grid[0].size();

        for(int j = 0; j < col; j++){
            if(grid[0][j] == 0 && dfs(grid,0,j)) return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& g,int r,int c){
        int n = g.size(), m = g[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m) return false;
        if(g[r][c] != 0) return false;

        if(r == n-1) return true; // reached bottom

        g[r][c] = -1; // visited

        for(auto &d:dir)
            if(dfs(g, r+d[0], c+d[1])) return true;

        return false;
    }
};
