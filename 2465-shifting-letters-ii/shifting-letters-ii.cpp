class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pre(s.length(), 0);
        for(auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if(dir == 1) {
                pre[start]++;
                if(end + 1< s.length()) {
                    pre[end+1]--;
                }
            }
            else {
                pre[start]--;
                if(end + 1 < s.length()) {
                    pre[end+1]++;
                }
            }
        }
        for(int i = 1; i<pre.size();i++) {
            pre[i] = pre[i] + pre[i-1];
        }
        for(int i = 0; i < s.length(); i++) {
            int shift = (s[i] - 'a' + pre[i]) % 26;
            if (shift < 0) shift += 26; 
            s[i] = 'a' + shift;
        }
        return s;
    }
};