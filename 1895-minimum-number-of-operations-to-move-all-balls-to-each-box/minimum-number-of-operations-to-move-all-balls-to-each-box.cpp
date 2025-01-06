class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> pre(n,0);
        pre[0] = (boxes[0] == '0') ? 0:1;
        for(int i = 1; i<n; i++) {
            pre[i] = pre[i-1];
            if(boxes[i] == '1') {
                pre[i] += 1;
            }
        }
        int s = pre[n-1];
        vector<int> ans(n);
        for(int i = 1; i<n; i++) {
            if(boxes[i] == '1') {
                ans[0] += i;
            }
        }
        for(int i = 1; i<n; i++) {
            ans[i] = ans[i-1] + s - 2*(s - pre[i-1]);
        }
        return ans;
    }
};