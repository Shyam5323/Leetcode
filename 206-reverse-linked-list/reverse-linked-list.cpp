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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) 
            return head;

        std::vector<ListNode*> linked;
        ListNode* current = head;
        while(current != nullptr) {
            linked.push_back(current);
            current = current->next;
        }
        for(size_t i = linked.size() - 1; i > 0; i--) {
            linked[i]->next = linked[i - 1];
        }
        linked[0]->next = nullptr; 
        return linked[linked.size() - 1];
    }
};