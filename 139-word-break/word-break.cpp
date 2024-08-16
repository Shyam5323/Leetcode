class Solution {
public:
    bool recurse(string s, vector<string>& wordDict, int index, vector<int>& dp) {
        if (index == s.length()) return true;
        
        bool ans = false;
        bool check = false;
        if(dp[index] != -1) {
            return dp[index];
        }
        for (int i = 1; i + index <= s.length(); i++) {  
            if (find(wordDict.begin(), wordDict.end(), s.substr(index, i)) != wordDict.end()) {
                check = true;
                bool take = recurse(s, wordDict, index + i, dp);
                if (take) {
                    ans = true;
                    break;  
                }
            }
        }
        
        if (!check) {
            return dp[index]  =  0;
        }
        
        return dp[index] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1 , -1);
        return recurse(s, wordDict, 0 , dp);
    }
};
