class Solution {
public:
    int uniquePaths(int m, int n) {
        // The result is the number of ways to choose (m-1) movements out of (m-1) + (n-1) movements
        long result = 1;
        int totalMoves = m + n - 2; // Total moves to reach the bottom-right corner
        int choose = min(m - 1, n - 1); // Choose the smaller number to minimize calculations
        
        // Compute the combination (totalMoves choose choose) iteratively
        for (int i = 1; i <= choose; ++i) {
            result = result * (totalMoves - choose + i) / i;
        }
        
        return result;
    }
};
