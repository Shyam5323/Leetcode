class Solution {
public:
    long long countSteps(int curr, int n) {
        long long steps = 0;
        long long first = curr, last = curr;
        while (first <= n) {
            steps += min((long long)n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  
        
        while (k > 0) {
            long long steps = countSteps(curr, n);
            
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;  
    }
};
