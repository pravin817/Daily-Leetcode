class Solution {

    // Solution - 1 : Brute Force solution by checking the each pair without using the same element twice.
    private int[] solution1(int[] nums, int target) {
        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = 0; jIdx < nums.length; jIdx++) {

                // Check the condition
                if (nums[iIdx] + nums[jIdx] == target && iIdx != jIdx) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        return new int[] {-1, -1};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Coplexity  : O(1)
    */

    // Solution - 2 : Instead of starting the jIdx = 0 we can start the jIdx from iIdx + 1.
    private int[] solution2(int[] nums, int target) {

        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = iIdx + 1; jIdx < nums.length; jIdx++) {

                if (nums[iIdx] + nums[jIdx] == target) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        // If we don't found any pair of elements where sum of two numbers is equal to the target
        return new int[] {-1, -1};
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int[] twoSum(int[] nums, int target) {
        return solution2(nums, target);
    }
}