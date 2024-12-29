class Solution {
public:
    const int MOD = 1e9 + 7;

    int recurse(string& target, int nChar, int used, vector<vector<int>>& dp, vector<vector<int>>& freqMap) {
        if (nChar == target.length()) {
            return 1;
        }
        if (used >= freqMap.size()) {
            return 0;
        }
        if (dp[nChar][used] != -1) {
            return dp[nChar][used];
        }
        char c = target[nChar];
        int useThis = (freqMap[used][c - 'a'] * 1LL * recurse(target, nChar + 1, used + 1, dp, freqMap)) % MOD;
        int notUseThis = recurse(target, nChar, used + 1, dp, freqMap);

        dp[nChar][used] = (useThis + notUseThis) % MOD;
        return dp[nChar][used];
    }

    int numWays(vector<string>& words, string target) {
        vector<vector<int>> freqMap(words[0].length(), vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < word.size(); j++) {
                freqMap[j][word[j] - 'a']++;
            }
        }
        vector<vector<int>> dp(target.length(), vector<int>(words[0].length(), -1));
        return recurse(target, 0, 0, dp, freqMap);
    }
};
