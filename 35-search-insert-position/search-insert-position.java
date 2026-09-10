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
    
    /**
        Optimal Solution - Usig Binary Search

        As the array is sorted and elements in the array are distinct then we can use the binary search to find the index of the target if present in the array else the position at which we can put the target element in the array    
    */
    private int searchIndexBinarySearch(int[] nums, int target) {
        int start = 0;
        int end   = nums.length - 1;

        while (start <= end) {
    
            // Find the mid element
            int mid = start + (end - start) / 2;

            // Return the index of the target elememt
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // Return the index at which we can insert the target element
        return start;
    }
    /*
        Analysis:
            Time Compleixty  : O(log n)
            Space Complexity : O(1)
    */


    public int searchInsert(int[] nums, int target) {
        return searchIndexBinarySearch(nums, target);
    }
}