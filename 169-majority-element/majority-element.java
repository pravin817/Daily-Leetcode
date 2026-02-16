class Solution {

    //Brute Force solution
    private int bruteForceSolution(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        return nums[length/2];
    }
    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */


    public int majorityElement(int[] nums) {
        return bruteForceSolution(nums);
    }
}