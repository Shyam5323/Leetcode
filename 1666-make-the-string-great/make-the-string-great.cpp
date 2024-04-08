class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        for(int i = 0; i<len-1; i++) {
            cout<<abs(int(s[i]) - int(s[i+1]))<<endl;
            if( abs(int(s[i]) - int(s[i+1])) ==  32) {
                s.erase(i,2);
                cout<<s<<endl;
                i=-1;
                
            }
        }
        return s;
    }
};