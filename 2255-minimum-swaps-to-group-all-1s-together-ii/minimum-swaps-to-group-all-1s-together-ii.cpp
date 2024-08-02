class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = count(nums.begin(), nums.end(), 1);
        int one = 0;
        for(int i = 0; i<ones; i++) {
            if(nums[i] == 1) {
                one++;
            }
        }
        int maxOne = one;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                one--;
            }
            if(nums[(i + ones) % nums.size()] == 1) {
                one++;
            }
            maxOne = max(maxOne, one);
        }
        return ones - maxOne;
    }
};