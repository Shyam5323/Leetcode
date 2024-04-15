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
    int traverse(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        int ans = 0;
        st.push({root , root->val});
        while(!st.empty()) {
            TreeNode* current = st.top().first;
            int sum = st.top().second;
            st.pop();
            if(current->right) {
                st.push({current->right , sum * 10 + current->right->val});
            }
            if(current->left) {
                st.push({current->left, sum * 10 + current->left->val});
            }
            if(!current->left && !current->right) {
                ans += sum;
            }
        }
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        return traverse(root);
    }
};