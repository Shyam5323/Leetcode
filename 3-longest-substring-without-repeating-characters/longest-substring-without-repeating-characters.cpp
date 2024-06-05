class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if (s.empty()) {
            return 0; 
        }
        if(s.length() == 1) {
            return 1;
        }
        int low = 0;
        int high = 1;
        int ans = 0;
        unordered_map<char,int> mp;
        for(char c:s) {
            mp[c] = 0;
        }
        mp[s[0]]++;
        while(high < s.length()) {
            if(mp[s[high]] == 0) {
                mp[s[high]]++;
                high++;
            }
            else {
                while(mp[s[high]] != 0) {
                    mp[s[low++]]--;
                }
            }
            ans = max(ans,high-low);
        }
        return ans;
    }
};