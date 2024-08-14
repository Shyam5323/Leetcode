class Solution {
    public int minPath(int[][] grid, int r, int c, int[][] dp) {
        if(r == grid.length - 1 && c == grid[0].length - 1) {
            return grid[r][c];
        }
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        int goDown = Integer.MAX_VALUE;
        int goRight = Integer.MAX_VALUE;
        if(r < grid.length - 1) {
             goDown = grid[r][c] + minPath(grid, r+1 ,c, dp);
        }
        if(c < grid[0].length - 1) {
             goRight = grid[r][c] + minPath(grid, r, c+1, dp);
        }

        return dp[r][c] = Math.min(goDown, goRight);
    }
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                dp[i][j] = -1;
            }
        }
        return minPath(grid, 0, 0,dp);
    }
}