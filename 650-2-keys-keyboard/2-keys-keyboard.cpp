
class Solution {
public:
    long long recurse(int current, int copied, int target) {
        if (current == target) {
            return 0; 
        }
        if (current > target) {
            return INT_MAX; 
        }

        long long noCopy = INT_MAX;
        long long copy = INT_MAX;


        if (copied != 0) {
            noCopy = 1 + recurse(current + copied, copied, target);
        }
        
        copy = 2 + recurse(2 * current, current, target);

        return min(copy, noCopy);
    }

    int minSteps(int n) {
        if (n == 1) {
            return 0; 
        }
        return recurse(1, 0, n); 
    }
};
