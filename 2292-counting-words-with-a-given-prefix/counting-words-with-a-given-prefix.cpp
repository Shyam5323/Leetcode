class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int len = pref.length();
        for(string word : words) {
            if(word.substr(0, len) == pref) {
                count++;
            }
        }
        return count;
    }
};