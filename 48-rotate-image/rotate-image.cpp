class Solution {
public:
    void reverseColumns(vector<vector<int>>& matrix) {
        int cols = matrix[0].size();
        
        for (int i = 0; i < matrix.size(); ++i) {
            int left = 0;
            int right = cols - 1;
            
            while (left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        reverseColumns(matrix);

    }
};