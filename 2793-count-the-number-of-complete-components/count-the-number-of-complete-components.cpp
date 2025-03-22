class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> nodes;
                dfs(i, adj, vis, nodes);
                
                bool isComplete = true;
                for (int node : nodes) {
                    if (adj[node].size() != nodes.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) count++;
            }
        }
        return count;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& nodes) {
        vis[node] = true;
        nodes.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, nodes);
            }
        }
    }
};
