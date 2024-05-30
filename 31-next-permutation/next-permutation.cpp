class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        int right = n - 1;
        int left = n - 2;
        
        while (left >= 0 && nums[left] >= nums[right]) {
            left--;
            right--;
        }
        
        if (left >= 0) {
            int minI = -1;
            int minD = INT_MAX;
            for (int i = left + 1; i < nums.size(); i++) {
                if (nums[i] > nums[left] && nums[i] < minD) {
                    cout<<i<<endl;
                    minD = nums[i];
                    minI = i;
                }
            }
            std::swap(nums[left], nums[minI]);
            cout<<left << " " << minI;
            std::sort(nums.begin() + left + 1, nums.end());
        } else {
            std::reverse(nums.begin(), nums.end());
        }
    }
};