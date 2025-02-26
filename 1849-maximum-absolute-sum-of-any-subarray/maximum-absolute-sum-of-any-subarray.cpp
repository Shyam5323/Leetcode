class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size() + 1);
        dp[0].first = nums[0];
        dp[0].second = nums[0];
        int ans = 0;
        ans = max(ans, abs(dp[0].first));
        ans = max(ans, abs(dp[0].second));
        for(int i = 1; i<nums.size(); i++) {
            dp[i].first = max(nums[i], nums[i] + dp[i-1].first);
            dp[i].second = min(nums[i], nums[i] + dp[i-1].second);
            ans = max(ans, abs(dp[i].first));
            ans = max(ans, abs(dp[i].second));
        }
   
    
        return ans;
    }
};