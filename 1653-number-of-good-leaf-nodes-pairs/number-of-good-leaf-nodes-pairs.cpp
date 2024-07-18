class Solution {
public:
    vector<int> help(TreeNode* root, int distance, int& ans) {
        if(!root) {
            return {};
        }
        if(root->left == nullptr && root->right == nullptr) {
            return {1}; // Leaf node distance is 1 from itself
        }

        auto l = help(root->left, distance, ans);
        auto r = help(root->right, distance, ans);

        // Count pairs of leaf nodes from left and right subtrees
        for(auto a : l) {
            for(auto b : r) {
                if(a + b <= distance) {
                    ans++;
                }
            }
        }

        vector<int> ret;
        // Update distances for left subtree
        for(auto a : l) {
            if(a + 1 < distance) {
                ret.push_back(a + 1);
            }
        }
        // Update distances for right subtree
        for(auto a : r) {
            if(a + 1 < distance) {
                ret.push_back(a + 1);
            }
        }

        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        help(root, distance, ans);
        return ans;
    }
};
