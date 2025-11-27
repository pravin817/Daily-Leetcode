class Solution {

    private int solutionOne(int[] nums) {
        int maxSum = Integer.MIN_VALUE;

        for(int i = 0; i < nums.length; ++i) {
            for(int j = i; j < nums.length; ++j) {
                int currentSum = 0;
                for (int k = i; k <= j; ++k) {
                    currentSum += nums[k];
                }

                maxSum = Math.max(maxSum, currentSum);
            }
        }

        return maxSum;
    }

    /*
        Analysis:
            Time Complexity  : O(n^3)
            Space Complexity : O(1)
    */

    // Note: As the above solution is not optimised and gives the TLE we need to optimsed this solution further.

    private int solutionTwo(int[] nums) {
        int maxSum = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; ++i) {
            int currentSum = 0;

            for (int j = i; j < nums.length; ++j) {
                currentSum += nums[j];
                maxSum = Math.max(maxSum, currentSum);
            }
        }

        return maxSum;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // We can further optimised this solution by using the kadane's algorithm
    private int solutionThree(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int i = 0; i < nums.length; ++i) {
            currentSum += nums[i];
            maxSum = Math.max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
    /*
        Analysis:
            Time complexity  : O(n)
            Space complexity : O(1)
    */

    public int maxSubArray(int[] nums) {
        return solutionThree(nums);
    }
}