class Solution {
public:
    unordered_set<int> visited;
    set<int> removed;
    void dfs(vector<vector<int>>& graph, int root) {
        if(visited.find(root) != visited.end()) {
            return;
        } 
        visited.insert(root);
        bool flag = true;
        for(int i = 0; i<graph[root].size(); i++) {
            if(removed.find(graph[root][i]) == removed.end() && visited.find(graph[root][i]) != visited.end()) {
                flag = false;
            } 
            else if(visited.find(graph[root][i]) == visited.end()) {
                dfs(graph, graph[root][i]);
                i--;
            }
        }
        if(flag) {
            removed.insert(root);
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i = 0; i<graph.size(); i++) {
            dfs(graph, i);
        }
        return vector<int>(removed.begin(), removed.end());

    }
};