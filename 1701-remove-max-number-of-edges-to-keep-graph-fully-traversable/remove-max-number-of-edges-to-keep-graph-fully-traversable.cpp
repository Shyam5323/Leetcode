class Solution {
public:
    int find(int u, vector<int>& representative) {
        if (u == representative[u])
            return u;
        else
            return representative[u] = find(representative[u], representative);
    }

    void combine(int u, int v, vector<int>& representative, vector<int>& size) {
        u = find(u, representative);
        v = find(v, representative);

        if (u == v)
            return;

        if (size[u] > size[v]) {
            representative[v] = u;
            size[u] += size[v];
        } else {
            representative[u] = v;
            size[v] += size[u];
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> repA(n + 1), repB(n + 1), sizeA(n + 1, 1), sizeB(n + 1, 1);
        iota(repA.begin(), repA.end(), 0);
        iota(repB.begin(), repB.end(), 0);

        int requiredEdges = 0;

        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (find(edge[1], repA) != find(edge[2], repA)) {
                    combine(edge[1], edge[2], repA, sizeA);
                    combine(edge[1], edge[2], repB, sizeB);
                    requiredEdges++;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (find(edge[1], repA) != find(edge[2], repA)) {
                    combine(edge[1], edge[2], repA, sizeA);
                    requiredEdges++;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (find(edge[1], repB) != find(edge[2], repB)) {
                    combine(edge[1], edge[2], repB, sizeB);
                    requiredEdges++;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (find(i, repA) != find(1, repA) || find(i, repB) != find(1, repB)) {
                return -1;
            }
        }

        return edges.size() - requiredEdges;
    }
};
