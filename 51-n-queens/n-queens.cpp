class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void helper(int n, vector<vector<string>>& ans, int row, vector<string>& curr) {
        if (row == n) {
            ans.push_back(curr);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(curr, row, col, n)) {
                curr[row][col] = 'Q'; 
                helper(n, ans, row + 1, curr); 
                curr[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.')); 
        helper(n, ans, 0, curr); 
        return ans;
    }
};
