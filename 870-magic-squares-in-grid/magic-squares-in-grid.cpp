class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> nums;
        int sum = 0;
        
        for (int i = 0; i < 3; i++) {
            int num = grid[row][col + i];
            if (num < 1 || num > 9 || nums.count(num)) return false;
            nums.insert(num);
            sum += num;
        }
        
        for (int i = 1; i < 3; i++) {
            int rowSum = 0;
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || nums.count(num)) return false;
                nums.insert(num);
                rowSum += num;
            }
            if (rowSum != sum) return false;
        }
        
        for (int j = 0; j < 3; j++) {
            int colSum = 0;
            for (int i = 0; i < 3; i++) {
                colSum += grid[row + i][col + j];
            }
            if (colSum != sum) return false;
        }
        
        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        
        return diag1 == sum && diag2 == sum;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};