class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2; 
        if (!list2) return list1; 

        ListNode* head = nullptr;
        ListNode* prev = nullptr;

        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        prev = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        if (list1 != nullptr) {
            prev->next = list1;
        } else {
            prev->next = list2;
        }

        return head;
    }
};
