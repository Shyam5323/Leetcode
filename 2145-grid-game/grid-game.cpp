class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefix1(n + 1, 0);
        vector<long long> prefix2(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix1[i + 1] = prefix1[i] + grid[0][i];
            prefix2[i + 1] = prefix2[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            long long topRowRemaining = prefix1[n] - prefix1[i + 1];
            long long bottomRowBefore = prefix2[i];
            result = min(result, max(topRowRemaining, bottomRowBefore));
        }
        
        return result;
    }
};