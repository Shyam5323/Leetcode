class Solution {

    public boolean part(int[] nums, int sum, int index, int[][] dp) {
        if (sum == 0) {
            return true;
        }
        
        if (index >= nums.length || sum < 0) {
            return false;
        }

        if (dp[index][sum] != -1) {
            return dp[index][sum] == 1; 
        }

        // Recursive case: try including or excluding the current number
        boolean canTake = part(nums, sum - nums[index], index + 1, dp);
        boolean cantTake = part(nums, sum, index + 1, dp);

        boolean result = canTake || cantTake;

        // Store the result in dp array (convert boolean to int)
        dp[index][sum] = result ? 1 : 0;

        return result;
    }

    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is odd, we can't partition it into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        int[][] dp = new int[nums.length][targetSum + 1];

        // Initialize the dp array with -1 (indicating uncomputed states)
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j <= targetSum; j++) {
                dp[i][j] = -1;
            }
        }

        // Start the recursion with the full target sum
        return part(nums, targetSum, 0, dp);
    }
}
