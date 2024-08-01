class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string s : details) {
            if(s.substr(11,2) > "60") {
                ans++;
            }
        }
        return ans;
    }
};