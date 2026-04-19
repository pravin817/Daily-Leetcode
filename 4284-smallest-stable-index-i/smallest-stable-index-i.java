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
    
    public int firstStableIndex(int[] nums, int k) {
        return solution1(nums, k);
    }
}