class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(char c : s) {
            int ch = c-'a'+1;
            int a = 0;
            while(ch > 0) {
                a += ch%10;
                ch /=10;
            }
            ans += a;
        }
        int t = ans;
        for(int i = 0; i+1<k; i++) {
            ans = 0;
            while(t > 0) {
                ans += t%10;
                t/=10;
            }
            t = ans;
        }
        return ans;
    }
};