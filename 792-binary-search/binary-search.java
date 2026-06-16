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


    // Solution - 2 : As the elements of the array are sorted in the asceding order we can use the binary search to find the target element in the array. If the target element is found in the array then we will return its index else we will return -1 indicating that the target element is not present in the array.

    private int binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    /*
        Analyis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */


    // But here is small bug in the formula for the finding the mid of the array
    // The formula that we have used above was: 
    //    int mid = (left + right ) / 2;
    // What If the value of left and right is near equal to the Integer.MAX_VALUE in this case it will be overflow and gaves us negative value.
    // So inorder to resolve this issue we can use the same formula by modifying it as below
    // int mid = left + (right - left)
    //                  --------------
    //                         2
    // int mid = 2 * left + right - left
    //          -------------------------
    //                     2
    //         = left + right
    //          --------------
    //                2

    private int binarySearchImproved(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */

    public int search(int[] nums, int target) {
        return binarySearchImproved(nums, target);
    }
}