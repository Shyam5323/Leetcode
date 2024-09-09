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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        int row = 0;
        int col = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ans[row][col] = curr->val;
            curr = curr->next;
            int nextRow = row + dir[i % 4].first;
            int nextCol = col + dir[i % 4].second;
            
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || ans[nextRow][nextCol] != -1) {
                i++; 
                nextRow = row + dir[i % 4].first;
                nextCol = col + dir[i % 4].second;
            }
            
            row = nextRow;
            col = nextCol;
        }
        
        return ans;
    }
};
