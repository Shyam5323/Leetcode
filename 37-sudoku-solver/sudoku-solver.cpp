class Solution {
public:
    bool isSafe(vector<vector<char>>& board, char curr, int row, int col) {
        for(int i = 0; i<9; i++) {
            if(board[row][i] == curr) {
                return false;
            }
        }
        for(int i = 0; i<9; i++) {
            if(board[i][col] == curr) {
                return false;
            }
        }
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == curr) {
                    return false;
                }
            }
        }
        return true;
    }

        bool backtrack(vector<vector<char>>& board, int box) {
        if (box == 81) {
            return true; 
        }

        int row = box / 9;
        int col = box % 9;

        if (board[row][col] != '.') {
            return backtrack(board, box + 1);
        }

        for (char num = '1'; num <= '9'; num++) {
            if (isSafe(board, num, row, col)) {
                board[row][col] = num;
                if (backtrack(board, box + 1)) {
                    return true;
                }
                board[row][col] = '.'; 
            }
        }

        return false; 
    }

    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0);
    }
};