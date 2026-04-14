class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();
        if(r < 0 || c < 0 || r >= nr || c >= nc|| grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r-1, c) + dfs(grid, r, c-1) + dfs(grid, r+1, c) + dfs (grid, r, c+1);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int max_area =0;
        for(int r = 0; r < nr; r++){
            for(int c = 0; c< nc; c++){
                if(grid[r][c] == 1){
                    max_area = max(max_area, dfs(grid, r, c));
                }
            }
        }
        return max_area;

    }
};
