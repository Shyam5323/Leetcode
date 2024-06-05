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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0;
        int lenB = 0;
        while(currA != nullptr || currB != nullptr)  {
            if(currA != nullptr) {
                lenA++;
                currA = currA  -> next;
            }
            if(currB != nullptr) {
                lenB++;
                currB = currB  -> next;
            }
        }
        int difference = abs(lenA - lenB);
        ListNode* greater = nullptr;
        ListNode* lesser = nullptr;
        if(lenA >= lenB) {
            greater = headA;
            lesser = headB;
        }
        else{
            greater = headB;
            lesser = headA;
        }
        for(int i = 0; i<difference; i++) {
            greater = greater->next;
        }
        while(greater != nullptr) {
            if(greater == lesser) {
                return greater;
            }
            greater =  greater->next;
            lesser = lesser->next;
        }return nullptr;

    }
};