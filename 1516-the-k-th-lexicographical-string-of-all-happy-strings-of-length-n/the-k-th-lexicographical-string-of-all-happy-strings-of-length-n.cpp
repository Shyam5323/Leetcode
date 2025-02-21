class Solution {
public:
    vector<string> ans;
    void backtrack(string c, int n) {
        if(c.length() == n) {
            ans.push_back(c);
            return;
        }
        for(char i = 0; i < 3; i++) {
            char newChar = (char)('a' + i);
            if(c.length() > 0 && c[c.length() - 1] == newChar) {
                continue;
            }
            string newString = c + newChar;
            backtrack(newString, n);
        }
    }
    string getHappyString(int n, int k) {
         backtrack("", n);
         if(k > ans.size()) {
            return "";
         }
         sort(ans.begin(), ans.end());
         return ans[k-1];

    }
};