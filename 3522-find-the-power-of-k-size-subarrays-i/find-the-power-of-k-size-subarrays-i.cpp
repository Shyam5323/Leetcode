class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1); 

        for (int i = 0; i <= n - k; i++) { 
            int minElement = nums[i], maxElement = nums[i];
            bool isConsecutive = true;

            for (int j = i + 1; j < i + k; j++) {
                minElement = min(minElement, nums[j]);
                maxElement = max(maxElement, nums[j]);
                if (nums[j] != nums[j - 1] + 1) {
                    isConsecutive = false;
                }
            }

            if (isConsecutive) {
                res[i] = maxElement;
            } else {
                res[i] = -1;
            }
        }

        return res;
    }
};
