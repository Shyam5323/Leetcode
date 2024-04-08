class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int opened = 0;
        string ans = "";
        for (char c : s) {
            if (isalpha(c)) {
                ans+=c;
            }
            if(c==')') {
                if(opened > 0) {
                    ans+=c;
                    opened--;
                }
            }
            if(c=='(') {
                ans+=c;
                opened++;
            }
        }
        reverse(ans.begin(), ans.end());
        int closed = 0;
        int len = ans.length();
        for(int i = 0; i<ans.length(); i++)
        {
            if(ans[i]==')') {
                closed++;
            }
            if(ans[i]=='(') {
                if(closed == 0) {
                    ans.erase(i, 1);
                    i--;
                }
                else {
                    closed--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};