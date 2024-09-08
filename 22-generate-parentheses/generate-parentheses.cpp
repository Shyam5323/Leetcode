class Solution {
public:
    void recurse(int n, int left, int right, vector<string>& ans, string curr) {
        if(left < 0 || right < 0) {
            return;
        }
        if(left == 0 && right == 0) {
            ans.push_back(curr);
            return;
        }

        recurse(n,left-1,right,ans, curr + "(");
        if(right > left) {
            recurse(n,left,right-1, ans, curr + ")");
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recurse(n,n,n,ans,"") ;
        return ans;
    }
};