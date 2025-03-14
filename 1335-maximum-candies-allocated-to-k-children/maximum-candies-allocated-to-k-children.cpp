class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1; 
        int right = *max_element(candies.begin(), candies.end());
        while(left <= right) { 
            int mid = left + (right - left) / 2;
            if (possible(candies, mid, k)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;  
    }

    bool possible(vector<int>& candies, int mid, long long k) {
        long long curr = 0; 
        for(int i : candies) {
            curr += i / mid;
            if(curr >= k) return true;
        }
        return false;
    }
};
