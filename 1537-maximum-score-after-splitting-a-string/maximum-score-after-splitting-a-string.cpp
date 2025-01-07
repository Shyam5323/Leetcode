class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for(char c : s) {
            if(c == '1') {
                ones++;
            }
        }
        int ans = 0;
        int currscore = ones;
        for(int i = 0; i+1<s.length(); i++) {
            if(s[i] == '0') {
                currscore++;
            }
            else {
                currscore--;
            }
            ans = max(ans, currscore);
        }
        return ans;
    }
};