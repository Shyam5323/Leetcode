class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i+1<nums.size(); i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int idx = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i] , nums[idx]);
                idx++;
            }
        }
        return nums;
    }
};