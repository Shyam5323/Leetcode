class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Directions array for the 4 possible moves (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Initialize the queue with all initially rotten oranges and count fresh oranges
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // If there are no fresh oranges, no time is needed
        if(freshOranges == 0) return 0;

        int minutes = 0;

        // Perform BFS to rot adjacent fresh oranges
        while(!q.empty()) {
            int qSize = q.size();
            bool rotted = false;

            for(int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                for(auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    // If the new cell is within bounds and has a fresh orange
                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2; // Rot the fresh orange
                        q.push({newRow, newCol});
                        freshOranges--;
                        rotted = true;
                    }
                }
            }

            if(rotted) minutes++;
        }

        // If there are still fresh oranges left, return -1
        return freshOranges == 0 ? minutes : -1;
    }
};
