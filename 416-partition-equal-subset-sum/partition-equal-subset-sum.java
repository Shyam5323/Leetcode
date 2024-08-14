import java.util.HashMap;
import java.util.Map;

class Solution {
    private Map<String, Boolean> memo = new HashMap<>();

    public boolean part(int[] nums, int sum1, int sum2, int index) {
        // Base case: If we've considered all elements
        if (index == nums.length) {
            return sum1 == sum2;
        }

        // Create a unique key for the current state
        String key = index + ":" + (sum1 - sum2);

        // Check if this state has already been computed
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        // Recursive case: Try including the current element in either sum1 or sum2
        boolean canPartition = part(nums, sum1 + nums[index], sum2, index + 1) ||
                               part(nums, sum1, sum2 + nums[index], index + 1);

        // Store the result in the memoization map
        memo.put(key, canPartition);

        return canPartition;
    }

    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is odd, we cannot partition it into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        // Try to find a subset with a sum equal to half of the total sum
        return part(nums, 0, 0, 0);
    }
}
