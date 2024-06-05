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
class Solution {
public:
    ListNode* reverse(ListNode* headNext) {
        ListNode* current = headNext;
        ListNode* prev = nullptr;
        while(current != nullptr) {
        ListNode* tempNext = current->next;
        current->next = prev;
        prev = current;
        current = tempNext;
    }
    return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(fast != nullptr) {
            slow = slow->next;
        }
        prev->next = reverse(slow);
        slow = head;
        fast = prev->next;
        while(fast!=nullptr) {
            if(slow->val != fast->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};