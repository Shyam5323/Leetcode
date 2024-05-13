class Solution {
private:
int binaryRowSum(const std::vector<std::vector<int>>& grid) {
    int sum = 0;
    for (const auto& row : grid) {
        int rowSum = 0;
        for (int bit : row) {
            rowSum = (rowSum << 1) + bit; 
        }
        sum += rowSum;
    }
    return sum;
}

public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j<grid[0].size(); j++) {
                    grid[i][j] = (grid[i][j] == 0 ? 1 : 0);
                }
            }
        }
        for(int col = 1; col<grid[0].size(); col++) {
            int ones = 0;
            int zeros = 0;
            for(int row = 0; row<grid.size(); row++) {
                if(grid[row][col] == 0) {
                    zeros++;
                } 
                if(grid[row][col] == 1) {
                    ones++;
                } 
            }
            if(zeros > ones) {
                for(int row = 0; row<grid.size(); row++) {
                    grid[row][col] = (grid[row][col] == 0 ? 1 : 0);
                }
            }
         }

         return binaryRowSum(grid);
    }
};