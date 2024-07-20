class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
       vector<vector<int>> ans;
        for(int i = 0; i < rowSum.size(); ++i) {
            vector<int> v;
            int remaining = rowSum[i];
            for(int j = 0; j < colSum.size(); ++j) {
                int ele = min(remaining, colSum[j]);
                v.push_back(ele);
                colSum[j] -= ele;
                remaining -= ele;
            }
            ans.push_back(v);
        }
        return ans;

    }
};