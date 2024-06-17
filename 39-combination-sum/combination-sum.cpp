class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, int index, vector<int>& curr, int cumsum) {
        if (cumsum == target) {
            ans.push_back(curr);
            return;
        }
        
        if (index == candidates.size() || cumsum > target) {
            return;
        }
        
        curr.push_back(candidates[index]);
        helper(candidates, target, ans, index, curr, cumsum + candidates[index]);
        
        curr.pop_back();
        
        helper(candidates, target, ans, index + 1, curr, cumsum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, ans, 0, curr, 0);
        return ans;
    }
};
