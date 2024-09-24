class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=0;
        int num=0;
        for(int i = 1; i<=nums.size(); i++) {
            n = n^i;
            num = num^nums[i-1];
        }
        return n^num;

    }
};