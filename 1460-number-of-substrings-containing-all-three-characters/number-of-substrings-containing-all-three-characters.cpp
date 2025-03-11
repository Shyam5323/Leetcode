class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int l = 0, ans = 0;

        for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;

            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += s.length() - r;
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
