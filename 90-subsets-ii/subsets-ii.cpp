class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int index) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[index]);
        helper(ans, nums, curr, index + 1);
        curr.pop_back();
        
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        
        helper(ans, nums, curr, index + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());  
        helper(ans, nums, curr, 0);
        return ans;
    }
};
