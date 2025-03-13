class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        map<int, int> m;
        for (const vector<int>& l : firstList) {
            ++m[l[0]];
            --m[l[1]];
        }
        for (const vector<int>& l : secondList) {
            ++m[l[0]];
            --m[l[1]];
        }

        int cur = 0;
        vector<vector<int>> ret;
        bool st = false;
        for (const auto& [k, v] : m) {
            const int before = cur;
            cur += v;
            if (cur == before) {
                ret.push_back({k, k});
            }
            if (cur == 2) {
                st = true;
                ret.push_back({k, 0});
            }
            if (st && cur <= 1) {
                st = false;
                ret.back()[1] = k;
            }
        }
        return ret;
    }
};