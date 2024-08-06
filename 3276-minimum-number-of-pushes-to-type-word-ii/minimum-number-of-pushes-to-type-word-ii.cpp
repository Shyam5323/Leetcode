class Solution {
public:
    int minimumPushes(string word) {
        vector<int> charFreq(26,0);
        for(char c : word) {
            charFreq[c-'a']++;
        }
        sort(charFreq.begin(), charFreq.end() , greater<int>());
        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(i<8) {
                ans+=charFreq[i];
            }
            else if(i<16) {
                ans+=charFreq[i] * 2;
            }
            else if(i<24) {
                ans+=charFreq[i] * 3;
            }
            else {
                ans+=charFreq[i] * 4;
            }
        }
        return ans;
    }
};