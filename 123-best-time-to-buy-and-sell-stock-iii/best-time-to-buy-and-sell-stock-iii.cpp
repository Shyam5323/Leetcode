class Solution {
public:
    int recurse(vector<int>& prices, int transLeft, int currTrans, int idx, vector<vector<vector<int>>>& dp) {
        if (idx >= prices.size() || transLeft == 0) {
            return 0;
        }
        if (dp[idx][currTrans][transLeft] != -1) return dp[idx][currTrans][transLeft];
        
        int takes = 0;
        int noTakes = 0;

        if (currTrans == 0) { // Buy
            // Option 1: Buy at current index
            takes = -prices[idx] + recurse(prices, transLeft, 1, idx + 1, dp);
            // Option 2: Skip buying and move to the next index
            noTakes = recurse(prices, transLeft, 0, idx + 1, dp);
        } else if (currTrans == 1) { // Sell
            // Option 1: Sell at current index
            takes = prices[idx] + recurse(prices, transLeft - 1, 0, idx + 1, dp);
            // Option 2: Skip selling and move to the next index
            noTakes = recurse(prices, transLeft, 1, idx + 1, dp);
        }

        return dp[idx][currTrans][transLeft] = max(takes, noTakes);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return recurse(prices, 2, 0, 0, dp);
    }
};
