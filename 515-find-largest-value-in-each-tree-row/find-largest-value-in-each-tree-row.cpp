/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans, int depth) {
        if(root == nullptr) {
            return;
        }
        if(ans.size() > depth) {
            ans[depth] = max(ans[depth], root->val);
        }
        else {
            ans.push_back(root->val);
        }
        dfs(root->left, ans, depth+1);
        dfs(root->right, ans, depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};