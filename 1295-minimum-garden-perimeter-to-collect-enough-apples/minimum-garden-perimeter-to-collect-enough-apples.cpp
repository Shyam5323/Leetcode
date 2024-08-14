class Solution {
private:    
    static long long TotalApples(long long n) {
        long long n_sq = n*n;
        return 4*n_sq*(n+1)+2*n_sq+2*n;
    }

public:
    long long minimumPerimeter(long long neededApples) {

        long long low_n = 1;
        long long high_n = 100000; 

        while (low_n < high_n) {
            long long mid_n = low_n + (high_n-low_n) / 2;
            long long apples = TotalApples(mid_n);
            if (apples == neededApples) {
                return 8*mid_n;
            } else if (apples < neededApples) {
                low_n = mid_n+1;
            } else {
                high_n = mid_n;
            }
        }

        return 8*high_n;
    }
};