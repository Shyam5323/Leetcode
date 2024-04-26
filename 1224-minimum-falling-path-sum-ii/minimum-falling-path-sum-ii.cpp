class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        pair<int, int> minF = {INT_MAX, -1};
        pair<int, int> minS = {INT_MAX, -1};
        
        for(int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
            if (grid[0][i] < minF.first) {
                minS = minF; 
                minF = {grid[0][i], i}; 
            } else if (grid[0][i] < minS.first) {
                minS = {grid[0][i], i};
            }
        }
        
        for(int i = 1; i < n; i++) {
            pair<int, int> newMinF = {INT_MAX, -1};
            pair<int, int> newMinS = {INT_MAX, -1};
            for(int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j] + (j == minF.second ? minS.first : minF.first);
                if (dp[i][j] < newMinF.first) {
                    newMinS = newMinF; 
                    newMinF = {dp[i][j], j}; 
                } else if (dp[i][j] < newMinS.first) {
                    newMinS = {dp[i][j], j};
                }
            }
            minF = newMinF;
            minS = newMinS;
        }
        
        return minF.first;
    }
};
