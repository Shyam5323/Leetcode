class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;
        for (const auto& road : roads) {
            mp[road[0]]++;
            mp[road[1]]++;
        }

        vector<pair<int, int>> freq_vec(mp.begin(), mp.end());

        sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        long long int ans = 0;
        int importance = n;
        for (const auto& [city, freq] : freq_vec) {
            ans += static_cast<long long>(importance) * freq;
            importance--;
        }

        return ans;
    }
};
