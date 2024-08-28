class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis, int row, int col, bool& isSubIsland) {
        if (row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size() || vis[row][col] || grid2[row][col] == 0)
            return;
        
        vis[row][col] = true;

        if (grid1[row][col] == 0)
            isSubIsland = false;
        
        dfs(grid1, grid2, vis, row + 1, col, isSubIsland); 
        dfs(grid1, grid2, vis, row - 1, col, isSubIsland); 
        dfs(grid1, grid2, vis, row, col + 1, isSubIsland); 
        dfs(grid1, grid2, vis, row, col - 1, isSubIsland); 
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start a DFS if we find an unvisited land cell in grid2
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    bool isSubIsland = true; // Assume it's a sub-island until proven otherwise
                    dfs(grid1, grid2, vis, i, j, isSubIsland);
                    if (isSubIsland)
                        ans++; // Increment if it's confirmed to be a sub-island
                }
            }
        }

        return ans;
    }
};
