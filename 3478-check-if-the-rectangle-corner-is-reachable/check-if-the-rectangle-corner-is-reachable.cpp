#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int num_circles = circles.size();
        vector<vector<int>> graph = buildGraph(X, Y, circles, num_circles);
        
        bool is_blocked = false;
        
        // Check from bottom-left corner
        is_blocked = bfs(num_circles, graph, num_circles, num_circles + 1, num_circles + 2);
        
        // Check from top-right corner
        is_blocked = is_blocked || bfs(num_circles, graph, num_circles + 3, num_circles + 2, num_circles + 1);
        
        return !is_blocked;
    }

private:
    vector<vector<int>> buildGraph(int X, int Y, vector<vector<int>>& circles, int num_circles) {
        vector<vector<int>> graph(num_circles + 4);

        for (int i = 0; i < num_circles; i++) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];

            if (x <= r) {
                graph[num_circles].push_back(i);
                graph[i].push_back(num_circles);
            }
            if (X - x <= r) {
                graph[num_circles + 2].push_back(i);
                graph[i].push_back(num_circles + 2);
            }
            if (y <= r) {
                graph[num_circles + 1].push_back(i);
                graph[i].push_back(num_circles + 1);
            }
            if (Y - y <= r) {
                graph[num_circles + 3].push_back(i);
                graph[i].push_back(num_circles + 3);
            }

            for (int j = i + 1; j < num_circles; j++) {
                int xj = circles[j][0];
                int yj = circles[j][1];
                int rj = circles[j][2];

                double distance = sqrt(pow(x - xj, 2) + pow(y - yj, 2));
                double radius_sum = r + rj;

                if (radius_sum >= distance) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        return graph;
    }

    bool bfs(int num_circles, vector<vector<int>>& graph, int start, int target1, int target2) {
        queue<int> q;
        vector<bool> visited(num_circles + 4, false);
        
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return visited[target1] || visited[target2];
    }
};

