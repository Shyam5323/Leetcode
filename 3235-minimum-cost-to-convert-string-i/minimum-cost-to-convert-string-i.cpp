class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
    int n = original.size();
    
    // Initialize the graph
    for (int i = 0; i < 26; i++) {
        dist[i][i] = 0;  // Cost to change a character to itself is 0
    }
    
    // Create the graph
    for (int i = 0; i < n; i++) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        dist[from][to] = min(dist[from][to], (long long)cost[i]);
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Calculate the minimum cost to transform source to target
    long long totalCost = 0;
    for (int i = 0; i < source.length(); i++) {
        int from = source[i] - 'a';
        int to = target[i] - 'a';
        if (from != to) {
            if (dist[from][to] == LLONG_MAX) {
                return -1;  // Impossible to transform
            }
            totalCost += dist[from][to];
        }
    }

    return totalCost;
}
};