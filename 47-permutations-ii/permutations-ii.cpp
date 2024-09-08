#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;  // Skip duplicates
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, used);
            used[i] = false;
            current.pop_back();
        }
    }
    
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtrack(nums, result, current, used);
        return result;
    }
};
