class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1}; 

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - lastCritical);
                }
                lastCritical = index;
            }
            prev = curr;
            curr = next;
            index++;
        }

        if (firstCritical == lastCritical) {
            return {-1, -1};  
        }

        int maxDistance = lastCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};