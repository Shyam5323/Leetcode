
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        if (!root) return ans;
        
        stack<pair<TreeNode*, TreeNode*>> st; // pair of current node and its parent
        st.push({root, nullptr});
        
        // If root is not to be deleted, add it to the answer
        if (to_delete_set.find(root->val) == to_delete_set.end()) {
            ans.push_back(root);
        }
        
        while (!st.empty()) {
            auto [node, parent] = st.top();
            st.pop();
            
            // Push children onto the stack with the current node as their parent
            if (node->right) {
                st.push({node->right, node});
            }
            if (node->left) {
                st.push({node->left, node});
            }
            
            // If the current node is in the to_delete set
            if (to_delete_set.find(node->val) != to_delete_set.end()) {
                // If it has children, they become new roots
                if (node->left && to_delete_set.find(node->left->val) == to_delete_set.end()) {
                    ans.push_back(node->left);
                }
                if (node->right && to_delete_set.find(node->right->val) == to_delete_set.end()) {
                    ans.push_back(node->right);
                }
                
                // Disconnect the node from its parent
                if (parent) {
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else if (parent->right == node) {
                        parent->right = nullptr;
                    }
                }
            }
        }
        
        return ans;
    }
};