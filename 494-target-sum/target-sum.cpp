class Solution {
public:
    void recurse(vector<int>& nums, int target, int index, int& count, int sum) {
        if(index >= nums.size() ) {
            if(sum == target) {
                count++;
            }
            return;
        }
        recurse(nums, target, index+ 1, count, sum + nums[index]);
        recurse(nums, target, index+ 1, count, sum - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        recurse(nums, target, 0, count, 0);
        return count;
    }
};