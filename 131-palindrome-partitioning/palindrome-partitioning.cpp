class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left<right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
    void helper(string s, vector<vector<string>>& ans, int left, vector<string> words) {
        if(left == s.length()) {
            ans.push_back(words);
            return;
        }
        for(int i = left; i<s.length(); i++) {
            string curr = s.substr(left, i - left + 1);
            if(isPalindrome(curr)) {
                words.push_back(curr);
                helper(s,ans,i+1, words);
                words.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> words;
        helper(s, ans, 0, words);
        return ans;
    }
};