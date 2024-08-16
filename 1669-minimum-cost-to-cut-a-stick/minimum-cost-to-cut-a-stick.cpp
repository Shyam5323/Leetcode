class Solution {
public:
    int cost(int i, int j, std::vector<int>& cuts, std::vector<std::vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int minCost = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int currentCost = cuts[j] - cuts[i];
            int leftCost = cost(i, k, cuts, dp);
            int rightCost = cost(k, j, cuts, dp);
            int totalCost = currentCost + leftCost + rightCost;
            minCost = std::min(minCost, totalCost);
        }

        if (minCost == INT_MAX) {
            return 0;
        }

        return dp[i][j] = minCost;
    }

    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, -1));
        
        return cost(0, m - 1, cuts, dp);
    }
};
