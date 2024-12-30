class Solution {
public:
    const int MOD = 1e9 + 7;

    int recurse(int low, int high, int zero, int one, int len, vector<int>& dp) {
        if (len > high) return 0;

        if(dp[len] != -1) {
            return dp[len];
        }
        int count = 0;
        if (len >= low && len <= high) {
            count = 1; 
        }

        count = (count + recurse(low, high, zero, one, len + zero, dp)) % MOD;
        count = (count + recurse(low, high, zero, one, len + one, dp)) % MOD;

        return dp[len] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return recurse(low, high, zero, one, 0, dp);
    }
};
