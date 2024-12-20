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
    unordered_map<int, stack<int>> oddLevels;
    void bfs(TreeNode* root, unordered_map<int, stack<int>>& oddLevels ) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int currLev = q.front().second;
            if(currLev%2 != 0) {
                oddLevels[currLev].push(curr->val);
            }
            q.pop();
            if(curr->left) {
                q.push({curr->left, currLev + 1});
            }
            if(curr->right) {
                q.push({curr->right, currLev + 1});
            }
        } 
    }
    void bfsUpdate(TreeNode* root, unordered_map<int, stack<int>>& oddLevels) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int currLev = q.front().second;
            if(currLev%2 != 0) {
                curr->val = oddLevels[currLev].top();
                oddLevels[currLev].pop();
            }
            q.pop();
            if(curr->left) {
                q.push({curr->left, currLev + 1});
            }
            if(curr->right) {
                q.push({curr->right, currLev + 1});
            }
        } 
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root, oddLevels);
        bfsUpdate(root, oddLevels);
        return root;
        
    }
};