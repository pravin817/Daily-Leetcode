class Solution {
    public int[] buildArray(int[] nums) {
        int[] result = new int[nums.length];

        for (int idx = 0; idx < nums.length; idx++) {
            result[idx] = nums[nums[idx]];
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity :  O(n)
            Space Complexity : O(1)
    */
}