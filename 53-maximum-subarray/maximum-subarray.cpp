#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_sum = dp[0]; // Initialize max_sum with the first element

        for(int i = 1; i < nums.size(); i++) {
            // If adding nums[i] to the previous sum results in a larger sum, update the sum
            dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
            // Update max_sum if necessary
            max_sum = std::max(max_sum, dp[i]);
        }
        
        return max_sum;
    }
};
