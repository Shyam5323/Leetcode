class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size());
        if(k == 0) {
            for(int i = 0; i<code.size(); i++) {
                ans[i] = 0;
            }
        }
        else if(k > 0) {
            for(int i = 0; i<code.size(); i++) {
                int sum = 0;
                for(int j = 1; j<=k; j++) {
                    sum += code[(i+j) % code.size()];
                }
                ans[i] = sum;
            }
        }
        else if (k < 0) {
            k = -k; 
            for (int i = 0; i < code.size(); i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += code[(i - j + code.size()) % code.size()];
                }
                ans[i] = sum;
            }
        }

        return ans;
    }
};