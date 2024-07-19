class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size() , INT_MAX);
        vector<int> cols(matrix[0].size(), INT_MIN);
        for (int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[0].size(); j++) {
                rows[i] = min(rows[i] , matrix[i][j]);
                cols[j] = max(cols[j] , matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[0].size(); j++) {
                if(matrix[i][j] <= rows[i] && matrix[i][j] >= cols[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};