class Solution {

    /**
     * Brute Force Solution - Linear Search
     *
     * Because the array is sorted, the first element >= target is either
     * the target itself (return its index) or the correct insert position.
     * If no such element exists, the target belongs at the end of the array.
     */
    private int searchIndexLinearSearch(int[] nums, int target) {

        for (int idx = 0; idx < nums.length; idx++) {
            if (nums[idx] >= target) {
                return idx;
            }
        }

        // Target is greater than all elements, insert at the end
        return nums.length;
    }

    /**
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    /**
     * Optimal Solution - Using Binary Search
     *
     * Because the array is sorted and contains distinct integers, we can use
     * binary search to find the target in O(log n) time.
     *
     * Key insight: when the loop exits without finding the target, start
     * always points to the first position where nums[start] > target,
     * which is exactly where the target should be inserted.
     */
    private int searchIndexBinarySearch(int[] nums, int target) {
        int start = 0;
        int end   = nums.length - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                // Target found, return its index
                return mid;
            } else if (nums[mid] > target) {
                // Target is in the left half
                end = mid - 1;
            } else {
                // Target is in the right half
                start = mid + 1;
            }
        }

        // Target not found; start is the correct insert position
        return start;
    }

    /*
        Analysis:
            Time Complexity  : O(log n)
            Space Complexity : O(1)
    */

    public int searchInsert(int[] nums, int target) {
        return searchIndexBinarySearch(nums, target);
    }
}