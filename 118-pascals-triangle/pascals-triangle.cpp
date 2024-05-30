class Solution {
public:
    unsigned long long factorial(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
unsigned long long combination(int n, int k) {
    if (k > n) {
        return 0; // Invalid case, n choose k is 0 if k > n
    }
    if (k == 0 || k == n) {
        return 1; // C(n, 0) = C(n, n) = 1
    }
    if (k > n - k) {
        k = n - k; // C(n, k) = C(n, n - k)
    }
    
    unsigned long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    
    return result;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                ans[i].push_back(combination(i, j));
            }
        }
        return ans;
    }
};