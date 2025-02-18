class Solution {
public:
    string recurse(string pattern, unordered_map<int,int> mp, string& num) {
        if(num.length() == pattern.length() + 1) {
            return num;
        }
        char cond = pattern[num.size()];
        if(num.size() > 0) {
            cond = pattern[num.size()-1];
        }
        int low = -1;
        int high = -1;
        if(num.size() == 0) {
            low = 1;
            high = 9;
        }
        else if(cond == 'I') {
            low = num[num.size() - 1] - '0' + 1;
            high = 9;
        }
        else if(cond == 'D') {
            low = 0;
            high = num[num.size() - 1] - '0' - 1;
        }
        for(int i = low; i<=high; i++) {
            if(mp[i] == -1) {
                mp[i] = 1;
                string nextNum = num + (char)('0' + i);
                string ans = recurse(pattern, mp, nextNum);
                if(ans.length() == pattern.length() + 1) {
                    return ans;
                }
                mp[i] = -1;
            } 
        }
        return num;
    }
    string smallestNumber(string pattern) {
        unordered_map<int,int> mp;
        for(int i = 1; i<=9; i++) {
            mp[i] = -1;
        }
        string num = "";
        return recurse(pattern, mp, num);
    }
};