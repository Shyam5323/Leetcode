class Solution {
public:
    int tribonacci(int n) {
        vector<int> series(38,0);
        series[1] = 1;
        series[2] = 1;
        for(int i = 3; i<=n; i++) {
            int sum = 0;
            for(int j = i - 1; j>= i-3; j--) {
                sum+=series[j];
            }
            series[i]  = sum;
        }
        return series[n];
    }
};