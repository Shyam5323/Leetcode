class Solution {
public:
    int maxAlternatingSubsequence(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int evenLen = 0, oddLen = 0;

        for (int num : nums) {
            if (num % 2 == 0) {
                evenLen = max(evenLen, oddLen + 1);
            } else {
                oddLen = max(oddLen, evenLen + 1);
            }
        }

        return max(evenLen, oddLen);
}
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int even = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even++;
            }
        }

        int odd = 0;
        for (int num : nums) {
            if (num % 2 == 1) {
                odd++;
            }
        }

        int alt = maxAlternatingSubsequence(nums);

        return max({even, odd, alt});
    }
};


