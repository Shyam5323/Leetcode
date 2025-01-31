#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int islandId) {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != 1) {
            return 0;
        }
        grid[row][col] = islandId;
        int size = 1;
        size += dfs(grid, row + 1, col, islandId);
        size += dfs(grid, row - 1, col, islandId);
        size += dfs(grid, row, col + 1, islandId);
        size += dfs(grid, row, col - 1, islandId);

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> islandSize;
        int islandId = 2; 
        int maxIslandSize = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSize[islandId] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    ++islandId;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> connectedIslands;
                    int potentialSize = 1; 

                    if (i > 0 && grid[i - 1][j] > 1) connectedIslands.insert(grid[i - 1][j]);
                    if (i < m - 1 && grid[i + 1][j] > 1) connectedIslands.insert(grid[i + 1][j]);
                    if (j > 0 && grid[i][j - 1] > 1) connectedIslands.insert(grid[i][j - 1]);
                    if (j < n - 1 && grid[i][j + 1] > 1) connectedIslands.insert(grid[i][j + 1]);

                    for (int id : connectedIslands) {
                        potentialSize += islandSize[id];
                    }

                    maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }

        return maxIslandSize > 0 ? maxIslandSize : m * n;
    }
};