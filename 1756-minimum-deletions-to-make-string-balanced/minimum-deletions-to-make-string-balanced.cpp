class Solution {
public:
    int minimumDeletions(string s) {
        int count_b = 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i = 0; i<n; i++) {
            if(s[i] == 'b') {
                count_b++;
                dp[i+1] = dp[i];
            }
            else{
                dp[i+1] = min(dp[i] + 1 , count_b);
            }
        } 
        return dp[n];
    }
};