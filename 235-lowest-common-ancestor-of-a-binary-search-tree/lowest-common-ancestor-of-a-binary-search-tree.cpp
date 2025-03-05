class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool& flag1, bool& flag2, TreeNode*& ans) {
        if (root == nullptr) return nullptr;

        bool leftFlag1 = false, leftFlag2 = false;
        bool rightFlag1 = false, rightFlag2 = false;
        
        TreeNode* left = dfs(root->left, p, q, leftFlag1, leftFlag2, ans);
        TreeNode* right = dfs(root->right, p, q, rightFlag1, rightFlag2, ans);
        
        flag1 = leftFlag1 || rightFlag1 || (root == p);
        flag2 = leftFlag2 || rightFlag2 || (root == q);

        if (flag1 && flag2 && ans == nullptr) {
            ans = root;
        }

        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        bool flag1 = false, flag2 = false;
        dfs(root, p, q, flag1, flag2, ans);
        return ans;
    }
};
