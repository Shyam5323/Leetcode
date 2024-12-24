class Solution {
public:
    int bfs(unordered_map<int, unordered_set<int>>& adj, int start) {
        queue<int> q;
        unordered_map<int, int> dist;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!dist.count(neighbor)) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    farthestNode = neighbor;
                }
            }
        }

        return farthestNode;
    }

    int calculateDiameter(unordered_map<int, unordered_set<int>>& adj) {
        int farthestNode = bfs(adj, 0);
        queue<int> q;
        unordered_map<int, int> dist;
        q.push(farthestNode);
        dist[farthestNode] = 0;
        int diameter = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!dist.count(neighbor)) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    diameter = max(diameter, dist[neighbor]);
                }
            }
        }

        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, unordered_set<int>> adj1, adj2;
        for (auto& edge : edges1) {
            adj1[edge[0]].insert(edge[1]);
            adj1[edge[1]].insert(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].insert(edge[1]);
            adj2[edge[1]].insert(edge[0]);
        }

        int diameter1 = calculateDiameter(adj1);
        int diameter2 = calculateDiameter(adj2);

        int minDiameter = max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});

        return minDiameter;
    }
};
