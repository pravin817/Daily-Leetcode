class Solution {

    // Function used to count the partitions count
    private int calculatePartitions(int[] nums) {
        int count = 0;
        int n = nums.length;

        for (int i = 0; i < n - 1; ++i) {
            int start = 0;

            // Sum from the start to mid [start, mid]
            int startSum  = 0;

            for (int j = start; j <= i; ++j) {
                startSum += nums[j];
            }

            // Calculate the sum from the [mid + 1, end]
            int endSum = 0;
            for(int j = i+1; j < n; ++j) {
                endSum += nums[j];
            }

            if ((endSum - startSum ) % 2 == 0) {
                ++count;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int countPartitions(int[] nums) {
        return calculatePartitions(nums);
    }
}