class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = 1LL * n * (n - 1) / 2; // Cast n to long long to prevent overflow

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i] - i]++;
        }

        for (const auto& pair : mp) {
            if (pair.second > 1) {
                total -= 1LL * pair.second * (pair.second - 1) / 2; // Handle overflow in pair counts
            }
        }

        return total;
    }
};
