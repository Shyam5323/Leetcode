class Solution {
public:
   ListNode* reverse(ListNode* start, ListNode* last) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while (curr != last) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            curr = curr->next;
            n++;
        }

        ListNode dummy(0); 
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        curr = head;
        while(curr != nullptr) {
            int a = 0;
            ListNode* start = curr;
            while(curr != nullptr && a < k) {
                curr = curr->next;
                a++;
            }
            ListNode* last = curr;
            if(a == k) {
                ListNode* newStart = reverse(start, last);
                prevGroupEnd->next = newStart;
                prevGroupEnd = start;
            } else {
                prevGroupEnd->next = start;
            }
        }
        return dummy.next; 
    }
};
