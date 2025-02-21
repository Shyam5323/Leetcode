class Solution {
public:
    int count = 0; 

    void backtrack(string& c, int n, string& ans, int k) {
        if (c.length() == n) {
            count++;  
            if (count == k) {
                ans = c;
                return;
            }
            return; 
        }
        for (char i = 0; i < 3; i++) {
            char newChar = 'a' + i;
            if (!c.empty() && c.back() == newChar) {
                continue;
            }
            c.push_back(newChar);
            backtrack(c, n, ans, k);
            if (!ans.empty()) return; 
            c.pop_back(); 
        }
    }

    string getHappyString(int n, int k) {
        string ans, c;
        count = 0;  
        backtrack(c, n, ans, k);
        return ans;
    }
};
