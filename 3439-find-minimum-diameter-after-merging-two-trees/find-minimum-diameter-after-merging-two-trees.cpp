class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto calculateDiameter = [&](unordered_map<int, unordered_set<int>>& adj) -> int {
            auto bfs = [&](int start) -> pair<int, int> {
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

                return {farthestNode, dist[farthestNode]};
            };
            auto [farthestNode, _] = bfs(0);
            auto [_, diameter] = bfs(farthestNode);
            return diameter;
        };

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

        int minDiameter = INT_MAX;

                minDiameter = min(minDiameter, max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1}));
         

        return minDiameter;
    }
};
