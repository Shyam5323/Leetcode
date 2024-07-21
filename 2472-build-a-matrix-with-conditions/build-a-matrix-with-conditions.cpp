class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> adjList(k + 1);
        vector<int> inDegree(k + 1, 0);
        vector<int> result;

        // Build the graph
        for (const auto& condition : conditions) {
            int u = condition[0];
            int v = condition[1];
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        // Initialize the queue with nodes of in-degree 0
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != k) {
            return {}; // Return an empty vector indicating a cycle or incomplete sort
        }

        return result;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {}; // If sorting failed, return an empty matrix
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; ++i) {
            for(int j = 0; j< k; j++) {
                if(rowOrder[i] == colOrder[j]) {
                    matrix[i][j] = rowOrder[i];
                }
            }
        }


        return matrix;
    }
};