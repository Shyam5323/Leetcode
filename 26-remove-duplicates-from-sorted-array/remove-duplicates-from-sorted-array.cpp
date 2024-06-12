class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 1;
        int count = 1;
        for(int i = 0; i+1<nums.size(); i++) {
            if(nums[i] != nums[i+1]) {
                nums[r++] = nums[i+1];
                count++;
            }
        }
        return count;
        
    }
};