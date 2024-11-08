class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xor1 = 0;
        for(int i : nums) {
            xor1 ^= i;
        }
        int mask = pow(2, maximumBit) - 1;
        vector<int> res(nums.size());
        for(int i = 0; i<nums.size(); i++) {
            res[i] = mask ^ xor1;
            xor1 ^= nums[nums.size()-i-1];
        }
        return res;
    }
};