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
    int findgcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=NULL){
            int gcd = findgcd(prev->val, curr->val);
            ListNode* x = new ListNode(gcd);
            prev->next = x;
            x->next = curr;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};