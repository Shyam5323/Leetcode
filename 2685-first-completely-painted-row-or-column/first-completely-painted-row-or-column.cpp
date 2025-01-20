class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        vector<pair<int, int>> positions(m * n + 1); 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positions[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = positions[arr[i]]; 
            rows[r]++;
            cols[c]++;         

            if (rows[r] == n || cols[c] == m) {
                return i;
            }
        }

        return -1;
    }
};
