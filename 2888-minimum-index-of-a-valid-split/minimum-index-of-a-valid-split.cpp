class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int count = 1;
        int freqE = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] == freqE) {
                count++;
            }
            else if(count > 0) {
                count--;
            }
            else {
                count = 1;
                freqE = nums[i];
            }
        }
        count = 0;
        for(int i : nums) {
            if(i == freqE) count++;
        }
        int currCount = 0;
        cout<<count;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == freqE) currCount++;
            if((currCount > (i+1)/2)  && ((count - currCount) > (nums.size() - i-1)/2)) return i;
        }
        return -1;
    }
};