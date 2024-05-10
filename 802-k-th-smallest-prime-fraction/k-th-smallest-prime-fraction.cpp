class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> fractions;
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                fractions.push_back({static_cast<double>(arr[i]) / arr[j], {i, j}});
            }
        }
        
        sort(fractions.begin(), fractions.end());
        
        return {arr[fractions[k - 1].second.first], arr[fractions[k - 1].second.second]};
    }
};
