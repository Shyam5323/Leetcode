class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char c1, c2;
        int count = 0;
        for(int i = 0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(count == 0) {
                    c1 = s1[i];
                    c2 = s2[i];
                }
                if(count == 1) {
                    if(!(c1 == s2[i] && c2 == s1[i])) {
                        return false;
                    }
                }
                else if(count > 1) {
                    return false;
                }
                count++;
            }
        }
        if(count == 1) {
            return false;
        }
        return true;
    }
};