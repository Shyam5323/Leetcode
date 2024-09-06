class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Initialize the dp table
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Iterate over the days in reverse order
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int currTrans = 0; currTrans <= 1; ++currTrans) {
                for (int transLeft = 1; transLeft <= 2; ++transLeft) {
                    if (currTrans == 0) { // Buy
                        dp[idx][currTrans][transLeft] = max(
                            -prices[idx] + dp[idx + 1][1][transLeft], // Buy the stock
                            dp[idx + 1][0][transLeft] // Skip the buy
                        );
                    } else { // Sell
                        dp[idx][currTrans][transLeft] = max(
                            prices[idx] + dp[idx + 1][0][transLeft - 1], // Sell the stock
                            dp[idx + 1][1][transLeft] // Skip the sell
                        );
                    }
                }
            }
        }

        // The result will be in dp[0][0][2]
        return dp[0][0][2];
    }
};
