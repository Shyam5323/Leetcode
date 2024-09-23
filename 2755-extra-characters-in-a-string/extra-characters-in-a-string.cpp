

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int minExtra = 1 + dp[i + 1];
            for (int end = i; end < n; ++end) {
                string substring = s.substr(i, end - i + 1);
                if (dict.find(substring) != dict.end()) {
                    minExtra = min(minExtra, dp[end + 1]);
                }
            }
            dp[i] = minExtra;
        }

        return dp[0];
    }
};
