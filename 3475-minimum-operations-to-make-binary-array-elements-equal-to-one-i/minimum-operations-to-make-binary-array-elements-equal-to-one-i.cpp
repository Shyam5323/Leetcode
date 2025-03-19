class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i+2<nums.size(); i++) {
            if(nums[i] == 0) {
                for(int j = i; j<i+3; j++) {
                    nums[j] = abs(nums[j] - 1);
                }
                ans++;
            }
        }
        for(int i : nums) {
            if(i == 0) return -1;
        }
        return ans;
    }
};