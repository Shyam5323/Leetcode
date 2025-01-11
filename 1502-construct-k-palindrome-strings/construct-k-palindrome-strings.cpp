class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) {
            return false;
        }
        if (k >= 26) return true;
        unordered_map<char,int> mp;
        int count{};
        for(char c : s) {
            mp[c]++;
            if(mp[c] % 2 != 0) {
                count++;
            }
            else {
                count--;
            }
        }
        if(count > k) {
            return false;
        }
        return true;
    }
};