/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int value = node->next->val;
        ListNode* nodes = node->next->next;
        node->val = value;
        node->next = nodes;
        
    }
};