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
    int traverse(TreeNode* root, bool isLeft) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right && isLeft) {
            return root->val;
        }
        int leftSum = traverse(root->left, true);
        int rightSum = traverse(root->right, false);
        return leftSum + rightSum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return traverse(root, 0);
    }
};