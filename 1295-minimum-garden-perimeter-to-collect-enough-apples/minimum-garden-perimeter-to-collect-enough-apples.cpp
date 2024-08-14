class Solution {
public:
    long long minimumPerimeter(long long n) {
        long long index = 0;
        for (long long i = 1;; ++i) {
            if (n <= 2 * i * (i + 1) * (2 * i + 1)) {
                index = i;
                break;
            }
        }
        return index * 8;
    }
};
