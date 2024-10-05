class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false; 

        vector<int> f1(26, 0);  
        vector<int> f2(26, 0);  

        for(char c : s1) {
            f1[c - 'a']++;
        }

        for(int i = 0; i < s2.length(); i++) {
            f2[s2[i] - 'a']++;

            if(i >= s1.length()) {
                f2[s2[i - s1.length()] - 'a']--;
            }

            if(f1 == f2) {
                return true;
            }
        }

        return false;
    }
};
