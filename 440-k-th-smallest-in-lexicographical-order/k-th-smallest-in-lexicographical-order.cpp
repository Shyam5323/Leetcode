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
        k--;  // We're counting from 0, so adjust k
        
        // While there are more digits to be found
        while (k > 0) {
            // Calculate the number of steps within the current subtree
            long long steps = countSteps(curr, n);
            
            if (steps <= k) {
                // If the current subtree size is less than or equal to k, move to the next sibling
                curr++;
                k -= steps;
            } else {
                // Otherwise, go down one level in the tree (append a zero to the current number)
                curr *= 10;
                k--;
            }
        }
        
        return curr;  // The k-th smallest number in lexicographical order
    }
};
