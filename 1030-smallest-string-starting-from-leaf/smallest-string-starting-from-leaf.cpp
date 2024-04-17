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
        string traverse(TreeNode* root) {
        string smallest = "";
        stack<pair<TreeNode*, string>> st;
        st.push({root, string(1, 'a' + root->val)}); 

        while (!st.empty()) {
            TreeNode* curr = st.top().first;
            string path = st.top().second;
            st.pop();

            if (!curr->left && !curr->right) {
                if (smallest == "" || path < smallest) {
                    smallest = path;
                }
            }

            if (curr->right) {
                st.push({curr->right, char('a' + curr->right->val) + path});
            }

            if (curr->left) {
                st.push({curr->left, char('a' + curr->left->val) + path});
            }
        }
        return smallest;
    }

    string smallestFromLeaf(TreeNode* root) {
        return traverse(root);
    }
};