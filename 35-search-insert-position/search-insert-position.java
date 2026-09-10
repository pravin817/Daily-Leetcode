class Solution {


    /**
        Brute Force Solution - Linear Search

        If we find the target element then returns its index else return the position
        where we can add this element   
    
    */
    private int searchIndexLinearSearch(int[] nums, int target) {

        for (int idx = 0; idx < nums.length; idx++) {
            if (nums[idx] == target) {
                return idx;
            } else if (nums[idx] > target) {
                return idx;
            }
        }

        // If the element is needed to add at the last of the array
        return nums.length;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int searchInsert(int[] nums, int target) {
        return searchIndexLinearSearch(nums, target);
    }
}