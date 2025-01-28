#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true; 
        int fishCount = grid[i][j];
        fishCount += dfs(grid, i + 1, j, visited);
        fishCount += dfs(grid, i - 1, j, visited);
        fishCount += dfs(grid, i, j + 1, visited);
        fishCount += dfs(grid, i, j - 1, visited);
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    ans = max(ans, dfs(grid, i, j, visited));
                }
            }
        }
        return ans;
    }
};