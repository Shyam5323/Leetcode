#include <vector>

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& land, int r, int c) {
        int topR = r;
        int topC = c;
        while (r + 1 < land.size() && land[r + 1][c] == 1) {
            r++;
        }
        while (c + 1 < land[0].size() && land[topR][c + 1] == 1) {
            c++;
        }
        for (int i = topR; i <= r; i++) {
            for (int j = topC; j <= c; j++) {
                land[i][j] = 0;
            }
        }
        return {topR, topC, r, c};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if(land[i][j] == 1) {
                    ans.push_back(dfs(land, i, j));
                }
            }
        }
        return ans;
    }
};
