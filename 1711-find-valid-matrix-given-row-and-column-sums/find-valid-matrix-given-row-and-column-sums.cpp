class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i = 0; i < rowSum.size(); ++i) {
            int remaining = rowSum[i];
            for(int j = 0; j < colSum.size(); ++j) {
                int ele = min(remaining, colSum[j]);
                ans[i][j] = ele;
                colSum[j] -= ele;
                remaining -= ele;
            }
        }
        return ans;
    }
};
