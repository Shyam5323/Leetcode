class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int top = 0;
        int bottom = rows - 1;
        int tRow = -1;
        
        while(top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if(matrix[mid][0] <= target && matrix[mid][cols - 1] >= target) {
                tRow = mid;
                break;
            } else if(matrix[mid][0] > target) {
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        
        if(tRow == -1) return false;
        
        int left = 0;
        int right = cols - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[tRow][mid] == target) {
                return true;
            } else if(matrix[tRow][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
