
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void iterativeDFS(int start, set<int>& ancestors) {
        stack<int> st;
        st.push(start);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (int parent : adj[node]) {
                if (ancestors.insert(parent).second) {
                    st.push(parent);
                }
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        for (auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            set<int> ancestors;
            iterativeDFS(i, ancestors);
            ans[i] = vector<int>(ancestors.begin(), ancestors.end());
        }      
        return ans;
    }
};
