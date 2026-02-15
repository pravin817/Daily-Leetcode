class Solution {

    // Brute Force solution
    private int[] solution(int[] nums) {
        int i = 0;
        int [] result = new int[nums.length];

        // Traverse the nums array
        for (int num: nums) {
            if (num != 0) {
                result[i++] = num;
            }
        }

        // Add the all remaining 0
        while (i < nums.length) {
            result[i++] = 0;
        }

        return result;
    } 

    // Function used to print the elements from the array
    private void logElements(int[] nums) {
        for (int num: nums) {
            System.out.println(num);
        }
    }

    public void moveZeroes(int[] nums) {
        int [] result = solution(nums);

        for (int i = 0; i < nums.length; ++i) {
            nums[i] = result[i];
        }
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}