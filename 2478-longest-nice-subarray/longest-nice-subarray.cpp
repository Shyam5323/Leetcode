class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0, andVal = 0, maxLen = 0;

        while (right < nums.size()) {
            while ((andVal & nums[right]) != 0) {
                andVal ^= nums[left]; 
                left++;
            }
            andVal |= nums[right]; 
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
