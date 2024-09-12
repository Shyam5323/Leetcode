class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        unordered_set<char> c;
        for(char ch : allowed) {
            c.insert(ch);
        }
        int count = 0;
        for(string word : words) {
            bool ad = true;
            for(char ch : word) {
                if(c.find(ch) == c.end()) {
                    ad = false;
                }
            }
            if(ad) {
                count++;
            }
        }
        return count;
    }
};