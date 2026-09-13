class Solution {

    // Brute Force solution - We need to find the index of the target element from the array. If the target element is present return it index else return -1
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

    // Optimal solution - As the array is sorted in the non decreasing order, we can use the binary search.
    private int binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // If the target element is not found in the array then return -1
        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */

    public int search(int[] nums, int target) {
        return binarySearch(nums, target);
    }
}