class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int max = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] == max) {
                count++;
            }
            else if(nums[i] != max && count == 1) {
                max = nums[i];
            }
            else{
                count--;
            }
        }
        return max;

    }
};