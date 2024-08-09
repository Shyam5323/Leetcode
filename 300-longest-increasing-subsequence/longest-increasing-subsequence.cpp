class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size(), 1);  // Initialize the DP array with 1, as the smallest LIS is 1.
        int maxLength = 1;  // Variable to keep track of the maximum length of LIS found so far.
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);  // Update the maximum length.
        }
        
        return maxLength;  // Return the maximum length of LIS found.
    }
};
