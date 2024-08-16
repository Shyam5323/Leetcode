
class Solution {
public:
    int coin(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;  
        }
        if (amount < 0) {
            return INT_MAX;  
        }
        if(dp[amount] != -1) {
            return dp[amount];
        }

        int ans = INT_MAX;  

        for (int c : coins) {
            int takes = coin(coins, amount - c, dp);
            if (takes != INT_MAX) {  
                ans = std::min(ans, 1 + takes);  
            }
        }

        return dp[amount] = ans;  
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = coin(coins, amount, dp);

        return result == INT_MAX ? -1 : result; 
    }
};
