class Solution {

    /**
    * Function  : runningSumSolution
      Purpose   : This function is used to calculate the running sum of an array.
      @param    : int[] nums, the input array
      @return   : int[] the resulting array containing the running sum
      @author   : Pravin Mhaske
      @date     : 29/06/2025
    */
    private int[] calculateRunningSum(int[] nums) {

        // 1. Validates the input array
        if (nums == null || nums.length == 0) {
            return new int[0];
        }

        int length = nums.length;

        int[] result = new int[length];

        result[0] = nums[0];

        for(int ithElement = 1; ithElement < length; ithElement++) {
            result[ithElement] = result[ithElement-1] + nums[ithElement];
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    // Function used to calculate the running sum of an array with modifying the original array - Not recommended

    private int[] calculateRunningSumInPlace(int[] nums) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }

        for(int ithElement = 1 ; ithElement < nums.length; ithElement++) {
            nums[ithElement] += nums[ithElement-1];
        }

        return nums;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1) --> We directly modified the input array
    */

    public int[] runningSum(int[] nums) {
        return calculateRunningSumInPlace(nums);
    }
}