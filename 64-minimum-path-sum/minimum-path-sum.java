class Solution {
    // public int minPath(int[][] grid, int r, int c, int[][] dp) {
    //     if(r == grid.length - 1 && c == grid[0].length - 1) {
    //         return grid[r][c];
    //     }
    //     if(dp[r][c] != -1) {
    //         return dp[r][c];
    //     }
    //     int goDown = Integer.MAX_VALUE;
    //     int goRight = Integer.MAX_VALUE;
    //     if(r < grid.length - 1) {
    //          goDown = grid[r][c] + minPath(grid, r+1 ,c, dp);
    //     }
    //     if(c < grid[0].length - 1) {
    //          goRight = grid[r][c] + minPath(grid, r, c+1, dp);
    //     }

    //     return dp[r][c] = Math.min(goDown, goRight);
    // }
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        dp[0][0] = grid[0][0];
        for(int i = 1; i<grid[0].length; i++) {
            dp[0][i] = grid[0][i] + dp[0][i-1]; 
        } 
        for(int i = 1; i<grid.length; i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int i = 1; i<grid.length; i++) {
            for(int j = 1; j<grid[0].length; j++) {
                dp[i][j] = grid[i][j] + Math.min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[grid.length - 1][grid[0].length - 1];
    }
}