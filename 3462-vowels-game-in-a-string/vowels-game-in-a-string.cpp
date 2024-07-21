class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel = 0;
        for(char c : s) {
            if( c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u') {
                vowel++;
            }
        }
        cout<<vowel;
        return (vowel == 0) ? false : true;
    }
};