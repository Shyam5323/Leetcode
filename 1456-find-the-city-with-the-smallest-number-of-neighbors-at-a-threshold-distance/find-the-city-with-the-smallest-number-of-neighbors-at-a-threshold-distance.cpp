class Solution {
public:
    void print(vector<int>& a) {
        for(int i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));
        
        // Initialize distances
        for(auto& v : edges) {
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];  // Undirected graph
        }
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int minReachableCities = INT_MAX;
        int result = -1;
        
        for(int i = 0; i < n; i++) {
            int reachableCities = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if(reachableCities <= minReachableCities) {
                if(reachableCities < minReachableCities) {
                    result = i;
                } else {
                    result = max(result, i);
                }
                minReachableCities = reachableCities;
            }
        }
        
        return result;
    }
};