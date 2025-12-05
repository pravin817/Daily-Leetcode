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

    // Note : We can optimised this solution to time complexity : O(n) and space complexity : O(n) using the prefixSum

    private int countPartitionsUsingPrefixSum(int[] nums) {
        int n = nums.length;
        int[] prefixSum = new int[n]; // O(n)
        int currentSum = 0, count = 0;

        // O(n)
        for (int end = n - 1; end >= 0; --end) {
            currentSum += nums[end];
            prefixSum[end] = currentSum;
        }

        // O(n)
        currentSum = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            currentSum += nums[i];

            if ((currentSum - prefixSum[i+1]) % 2 == 0) {
                count += 1;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int countPartitions(int[] nums) {
        return countPartitionsUsingPrefixSum(nums);
    }
}