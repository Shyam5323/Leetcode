class Solution {
public:
    int recurse(string s, int start, unordered_set<string> subs) {
        if(start >= s.length()) {
            return 0;
        }
        int ans = 0;
        for(int i = start; i<s.length(); i++) {
            if(subs.insert(s.substr(start, i-start+1)).second) {
                int divs = 1 + recurse(s, i + 1, subs);
                ans = max(ans, divs);
                subs.erase(s.substr(start, i-start+1));
            } 
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> subs;
        return recurse(s, 0, subs);
    }
};