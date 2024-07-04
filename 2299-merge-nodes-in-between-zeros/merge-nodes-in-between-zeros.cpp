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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        int sum = 0;

        while (second != nullptr) {
            if (second->val == 0) {
                // Set the value of the current node to the sum
                first->val = sum;
                sum = 0; // Reset sum for the next segment
                
                // Move the first pointer to the next position
                if (second->next != nullptr) {
                    first = first->next;
                }
            } else {
                // Accumulate the sum of values between zeros
                sum += second->val;
            }
            second = second->next;
        }

        // Terminate the modified list correctly
        first->next = nullptr;

        return head;
    }
};
