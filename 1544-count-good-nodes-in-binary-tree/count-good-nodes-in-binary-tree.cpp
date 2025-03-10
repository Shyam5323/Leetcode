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
    int dfs(TreeNode* root, int maxVal) {
        if(!root) return 0;
        if(root->val >= maxVal) {
            maxVal = root->val; 
            return 1 + dfs(root->right, maxVal) + dfs(root->left, maxVal);
        }
        return dfs(root->right, maxVal) + dfs(root->left, maxVal);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};