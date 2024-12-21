

class Solution {
public:
    void createTree(int n, vector<vector<int>>& edges, unordered_map<int, vector<int>>& tree) {
        for (int i = 0; i < n; ++i) {
            tree[i] = {};
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u); 
        }
    }

    long long dfs(int n, unordered_map<int, vector<int>>& tree, vector<int>& values, int k, int& count, int curr, unordered_set<int>& visited) {
        visited.insert(curr);

        long long subtreeSum = values[curr];

        for (int child : tree[curr]) {
            if (visited.find(child) != visited.end()) {
                continue;
            }
            subtreeSum += dfs(n, tree, values, k, count, child, visited);
        }

        if (subtreeSum % k == 0) {
            count++;
            return 0;
        }

        return subtreeSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> tree;
        createTree(n, edges, tree);

        int count = 0;
        dfs(n, tree, values, k, count, 0, visited);

        return count;
    }
};

