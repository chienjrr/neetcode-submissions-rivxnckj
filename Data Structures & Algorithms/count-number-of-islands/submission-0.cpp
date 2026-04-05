class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();
        if(r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);

    }


    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int nr = grid.size();
        int nc = grid[0].size();
        int numis = 0;
        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                if(grid[r][c] == '1'){
                    numis++;
                    dfs(grid, r, c);
                }
            }
        }
        return numis;

    }
};
