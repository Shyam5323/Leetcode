class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(n,1);
        int ans = 0;
        vector<int> dp2(26,0);
        for(int i = 0; i<n; i++) {
            int left = max(0, s[i] -'a' - k);
            int right = min(25,  s[i] -'a' + k);
            int mx = 0;
            for(int j = left; j<=right; j++) {
                mx = max(mx, dp2[j]);
            }
            dp[i] = mx+1;
            ans = max(ans,dp[i]);
            dp2[s[i] - 'a'] = max(dp2[s[i] - 'a'], dp[i]);
        }
        return ans;
    }
};