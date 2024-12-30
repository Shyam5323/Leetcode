class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1; 

        for (int len = 0; len <= high; ++len) {
            if (dp[len] > 0) {
                if (len + zero <= high) {
                    dp[len + zero] = (dp[len + zero] + dp[len]) % MOD;
                }
                if (len + one <= high) {
                    dp[len + one] = (dp[len + one] + dp[len]) % MOD;
                }
            }
        }

        int result = 0;
        for (int len = low; len <= high; ++len) {
            result = (result + dp[len]) % MOD;
        }

        return result;
    }
};
