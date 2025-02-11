class Solution {
public:
    string clearDigits(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                s[i] = ' ';
                int j = i - 1;
                while (j >= 0) {
                    if (!isdigit(s[j]) && s[j] != ' ') {
                      s[j] = ' ';
                      break;  
                    } 
                    j--;
                }
            }
        }

        string ans;
        for (char c : s) {
            if (c != ' ') ans += c;
        }
        return ans;
    }
};
