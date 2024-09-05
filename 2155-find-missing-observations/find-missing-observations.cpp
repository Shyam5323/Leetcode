class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int mSum = 0;
        for(int i : rolls) {
            mSum += i;
        }
        int nSum = mean*(m+n) - mSum;
        vector<int> ans;
        for(int i = n; i>0; i--) {
            int d = nSum / i;
            if(d>6) {
                d = 6;
            }
            if(d<=0) {
                return {};
            }
            nSum -= d;
            ans.push_back(d);
        }
        if(nSum > 0) {
            return {};
        }
        return ans;
    }
};