class Solution {
public:
    unordered_set<string> a;
    void recurse(vector<int>& counts, string curr, int len) {
        if (!curr.empty()) {
            a.insert(curr);
        }
        for(int i = 0; i<26; i++) {
            if(counts[i] > 0) {
                counts[i]--;
                string nextCurr = curr + (char)('A' + i);
                recurse(counts, nextCurr ,len);
                counts[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> counts(26, 0);
        for(char c : tiles) {
            counts[c - 'A']++;
        }
        recurse(counts, "", tiles.length());
        return a.size();
    }

};