class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); 
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0; 
                }
            }
        }

        vector<int> dir1 = {0, 0, 1, -1};
        vector<int> dir2 = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dir1[k];
                int nc = col + dir2[k];
                
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[row][col] + 1; 
                    q.push({nr, nc}); 
                }
            }
        }
        
        return ans;
    }
};
