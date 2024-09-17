class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxE = INT_MIN;
        int count = 0;
        
        for (int i : nums) {
            maxE = max(maxE, i);
        }
        
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxE) {
                curr++;
            } else {
                count = max(count, curr);
                curr = 0;
            }
        }
        
        count = max(count, curr);
        
        return count;
    }
};
