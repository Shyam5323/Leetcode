class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        if(n == 1){
            return ans;
        }
        for(int i = 0; i<n; i++) {
            ans += 4 * (i);
        }
        return ans;
    }
};