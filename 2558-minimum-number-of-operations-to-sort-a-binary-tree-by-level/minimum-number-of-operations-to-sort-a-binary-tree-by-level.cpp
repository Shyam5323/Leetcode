class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            vector<int> sortedLevel = currLevel;
            sort(sortedLevel.begin(), sortedLevel.end());
            unordered_map<int, int> indexMap;
            for (int i = 0; i < sortedLevel.size(); ++i) {
                indexMap[sortedLevel[i]] = i;
            }

            vector<bool> visited(currLevel.size(), false);
            int swaps = 0;
            for (int i = 0; i < currLevel.size(); ++i) {
                if (visited[i] || indexMap[currLevel[i]] == i) continue;
                int cycleSize = 0;
                int x = i;
                while (!visited[x]) {
                    visited[x] = true;
                    x = indexMap[currLevel[x]];
                    cycleSize++;
                }
                swaps += (cycleSize - 1);
            }
            ans += swaps;
        }

        return ans;
    }
};
