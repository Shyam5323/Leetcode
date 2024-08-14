class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int minD = 0;
        int maxD = nums[nums.size() - 1] - nums[0];

        while (minD < maxD) {
            int mid = minD + (maxD - minD) / 2;

            int count = 0;
            int left = 0;

            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) {
                    left++;
                }
                count += right - left;
            }

            if (count >= k) {
                maxD = mid;
            } else {
                minD = mid + 1;
            }
        }

        return minD;
    }
};
