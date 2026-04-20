class Solution {

    private int maximumElement(int[] nums, int start, int end) {
        int maxElement = Integer.MIN_VALUE;

        for (int i = start; i <= end; i++) {
            maxElement = Math.max(maxElement, nums[i]);
        }

        return maxElement;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    private int minimumElement(int[] nums, int start, int end) {
        int minElement = Integer.MAX_VALUE;

        for (int i = start; i <= end; i++) {
            minElement = Math.min(minElement, nums[i]);
        }

        return minElement;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    private int solution1(int[] nums, int k) {
        for (int i = 0; i < nums.length; i++) {
            int score = maximumElement(nums, 0, i) - minimumElement(nums, i, nums.length-1);

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    private int solution2(int[] nums, int k) {
        int n = nums.length;

        int[] maxiElement = new int[n];
        int[] miniElement = new int[n];

        // pre-compute the maxiElement
        int maxi = nums[0];
        for (int idx = 0; idx < n; idx++) {
            maxi = Math.max(maxi, nums[idx]);
            maxiElement[idx] = maxi;
        }

        // pre-compute the miniElement
        int mini = nums[n-1];
        for (int idx = n-1; idx >= 0; idx--) {
            mini = Math.min(mini, nums[idx]);
            miniElement[idx] = mini;
        }

        // Calculate the instability score
        for (int idx = 0; idx < n; idx++) {
            int instabilityScore = maxiElement[idx] - miniElement[idx];

            if (instabilityScore <= k) {
                return idx;
            }
        }

        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
    
    public int firstStableIndex(int[] nums, int k) {
        return solution2(nums, k);
    }
}