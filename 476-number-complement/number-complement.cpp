class Solution {
public:
    int findComplement(int num) {
        string bin = "";
        int n = num;
        while(n > 0) {
            if(n%2 == 0) {
                bin = "1" + bin;
            }
            else {
                bin = "0" + bin;
            }
            n = n/2;
        }
        int p = 0;
        int ans = 0;
        for(int i = bin.length()-1; i>=0;i--) {
            if(bin[i] == '1') {
                ans += pow(2,p);
            }
            p++;
        }
        return ans;

    }
};