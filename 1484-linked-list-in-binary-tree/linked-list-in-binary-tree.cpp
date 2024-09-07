/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true; // We've reached the end of the linked list, so it's a match
        }
        if (root == nullptr) {
            return false; // We've reached a leaf in the tree, but the list hasn't been fully matched
        }
        if (root->val == head->val) {
            // Continue the search down the tree
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        return false; // Values don't match, so return false
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        // Start a DFS from the root of the tree and check if the path matches
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
