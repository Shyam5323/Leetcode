class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> pre(nums.size() + 1);
        pre[0] = 0;
        pre[1]  = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        int ans = 0;
        for(int i = 1; i<nums.size(); i++) {
            if(pre[i] >= (pre[pre.size()-1] - pre[i])) {
                ans++;
            }
        }
        return ans;
    }
};