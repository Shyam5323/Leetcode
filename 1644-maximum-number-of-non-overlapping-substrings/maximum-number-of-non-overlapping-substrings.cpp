
class Solution {
public:
    vector<string> maxNumOfSubstrings(string S) {
        // Precompute mins, maxs and build prefix sum in O(N) time
        vector<int> mins(26, INT_MAX), maxs(26, -1);
        vector<vector<int>> prefixSum(S.length() + 1, vector<int>(26, 0));
        vector<bool> exists(26, false);
        
        for (int i = 0; i < S.length(); i++) {
            copy(prefixSum[i].begin(), prefixSum[i].end(), prefixSum[i + 1].begin());
            prefixSum[i + 1][S[i] - 'a'] += 1;
            mins[S[i] - 'a'] = min(mins[S[i] - 'a'], i);
            maxs[S[i] - 'a'] = max(maxs[S[i] - 'a'], i);
            exists[S[i] - 'a'] = true;
        }

        // Build graph using adjacency matrix
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                for (int j = 0; j < 26; j++) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0) {
                        graph[i][j] = true;
                    }
                }
            }
        }

        // Kosaraju's algorithm to find SCC
        stack<int> stk;
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; i++) {
            if (exists[i] && !visited[i]) {
                dfs(i, graph, stk, visited);
            }
        }

        int batch = 0; // 'id' of each SCC
        vector<int> batches(26, -1);
        vector<int> degree(26, 0); // out-degree of each SCC
        while (!stk.empty()) {
            int v = stk.top(); stk.pop();
            if (batches[v] < 0) {
                dfs(v, graph, batches, batch, degree);
                batch++;
            }
        }

        vector<string> res;
        for (int i = batch - 1; i >= 0; i--) {
            if (degree[i] == 0) {
                int minIndex = INT_MAX, maxIndex = -1;
                for (int j = 0; j < 26; j++) {
                    if (batches[j] == i) {
                        minIndex = min(mins[j], minIndex);
                        maxIndex = max(maxs[j], maxIndex);
                    }
                }
                res.push_back(S.substr(minIndex, maxIndex - minIndex + 1));
            }
        }

        return res;
    }

private:
    void dfs(int v, const vector<vector<bool>>& graph, stack<int>& stk, vector<bool>& visited) {
        if (!visited[v]) {
            visited[v] = true;
            for (int i = 0; i < 26; i++) {
                if (graph[v][i] && !visited[i]) {
                    dfs(i, graph, stk, visited);
                }
            }
            stk.push(v);
        }
    }

    void dfs(int v, const vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] < 0) {
            batches[v] = batch;
            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) {
                    dfs(i, graph, batches, batch, degree);
                }
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]] += 1;
            }
        }
    }
};
