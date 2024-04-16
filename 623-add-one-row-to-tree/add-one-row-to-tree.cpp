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
    void helper(TreeNode* root , int val , int depth, int currDepth) {
        if(root == nullptr) {
            return;
        }
        if(currDepth == depth - 1) {
            TreeNode* nodeLeft = new TreeNode(val);
            TreeNode* nodeRight = new TreeNode(val);
            nodeLeft -> left = root->left;
            nodeRight -> right = root->right;
            root -> left = nodeLeft;
            root -> right = nodeRight;
            return;
        }
        helper(root->left , val, depth, currDepth + 1);
        helper(root->right , val, depth, currDepth + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        helper(root, val, depth, 1);
        return root;
    }
};