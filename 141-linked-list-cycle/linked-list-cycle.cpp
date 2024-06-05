class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Check for the trivial cases first
        if (head == nullptr) {
            return false;
        }
        if (head->next == head) {
            return true;
        }
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Check for nullptr before accessing members of fast or slow
            if (fast != nullptr && slow == fast) {
                return true;
            }
        }
        return false;
    }
};
