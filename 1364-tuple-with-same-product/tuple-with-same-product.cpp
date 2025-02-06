class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> productCount;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j]; 
                productCount[product]++;         
            }
        }
        for (const auto& pair : productCount) {
            int count = pair.second;
            if (count > 1) {
                ans += (count * (count - 1)) / 2 * 8;
            }
        }

        return ans;
    }
};
