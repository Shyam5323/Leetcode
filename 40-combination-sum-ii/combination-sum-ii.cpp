class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, int index, vector<int> curr) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            helper(candidates, target - candidates[i], ans, i + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ans, 0, curr);
        return ans;
    }
};
