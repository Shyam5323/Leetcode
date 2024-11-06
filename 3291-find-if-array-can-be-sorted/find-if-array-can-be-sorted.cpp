class Solution {
public:
    int setBits(int num) {
        int ans = 0;
        while(num > 0) {
            if(num % 2 != 0) {
                ans++;
            }
            num/=2;
        }
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        int prev = INT_MIN;
        for(int i = 0; i<nums.size(); i++) {
            int maxE = nums[i];
            int minE = nums[i];
            int bits = setBits(nums[i]);
            int j = i+1;
            while(j<nums.size() && setBits(nums[j]) == bits) {
                maxE = max(maxE, nums[j]);
                minE = min(minE, nums[j]);
                j++;
            }
            if(minE < prev) {
                return false;
            }
            i = j-1;
            prev = maxE;
        }
        return true;
    }
};