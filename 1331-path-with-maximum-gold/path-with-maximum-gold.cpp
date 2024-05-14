class Solution {
public:

    int backtrack(vector<vector<int>>& grid, int row, int col, int sum) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) {
            return sum;
        }
        
        int gold = grid[row][col];
        sum += gold;
        grid[row][col] = 0; 
        int maxGold = sum;
        maxGold = max(maxGold, backtrack(grid, row + 1, col, sum));
        maxGold = max(maxGold, backtrack(grid, row - 1, col, sum));
        maxGold = max(maxGold, backtrack(grid, row, col + 1, sum));
        maxGold = max(maxGold, backtrack(grid, row, col - 1, sum));
        grid[row][col] = gold;

        return maxGold;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++) {
            for(int j =0; j<grid[0].size(); j++) {
                ans = max(ans,backtrack(grid,i,j,0));
            }
        }
        return ans;
    }
};