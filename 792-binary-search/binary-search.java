class Solution {


    // Brute Force Solution - We will check each element from the array one by one and returns the index where we found that element as there is always unique elements in the array. Here we can use the Linear Search

    private int linearSearch(int[] nums, int target) {
        for (int idx = 0; idx < nums.length; idx++) {
            if (nums[idx] == target) {
                return idx;
            }
        }

        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int search(int[] nums, int target) {
        return linearSearch(nums, target);
    }
}