class Solution {

    // Brute Force Solution
    private int countKDifferenceBruteForce(int[] nums, int k) {
        int counter = 0;

        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if(Math.abs(nums[i] - nums[j]) == k) {
                    ++counter;
                }
            }
        }

        return counter;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int countKDifference(int[] nums, int k) {
        return countKDifferenceBruteForce(nums, k);
    }
}