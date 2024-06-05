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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == nullptr) {
            return false;
        }
        if(head->next == head) {
            return true;
        }
        while(fast != nullptr && fast->next !=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast != nullptr && slow == fast) {
                return true;
            }
        }
        return false;
    }
};