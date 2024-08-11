class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c) {
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = 1;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        while(!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numberOfIslands(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int initialIslands = numberOfIslands(grid);
        if (initialIslands != 1) {
            return 0;
        }
        
        // Check if removing any single land cell disconnects the island
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int newIslands = numberOfIslands(grid);
                    if (newIslands > 1 || newIslands == 0) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        
        // If removing a single cell doesn't disconnect, return 2
        return 2;
    }
};
