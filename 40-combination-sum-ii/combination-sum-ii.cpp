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
        
        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            curr.push_back(candidates[i]);
            helper(candidates, target, ans, i + 1, curr, cumsum + candidates[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, ans, 0, curr, 0);
        return ans;
    }
};
