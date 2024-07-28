class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<pair<int,int>> v;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == '0') v.emplace_back(0, 1), i++;
            else {
                i++;
                int ln = 1;
                while (i < s.size() && s[i] == '1') {
                    ln++;
                    i++;
                }
                v.emplace_back(1, ln);
            }
        }
        int ans = 0;
        int at = 0;
        while (at < v.size()) {
            int c0 = 0, c1 = 0;
            for (int i = at; i < v.size(); i++) {
                if (c0 >= 205) break;
                if (v[i].first == 0) {
                    c0++;
                    if (c1 >= c0 * c0) ans++;
                } else {
                    int lo = 1, hi = v[i].second;
                    int bst = -1;
                    while (lo <= hi) {
                        int mi = (lo + hi) / 2;
                        if (c1 + mi >= c0 * c0) {
                            hi = mi - 1;
                            bst = mi;
                        } else {
                            lo = mi + 1;
                        }
                    }
                    if (bst != -1) ans += v[i].second - bst + 1;
                    c1 += v[i].second;
                }
            }
            v[at].second--;
            if (v[at].second == 0) {
                at++;
            }
        }
        return ans;
    }
};