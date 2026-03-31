class Solution {

    // Brute Force Solution by using two pointer
    private int solution1(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int count = 0;

        while(left < right) {
            if (nums[left] != target) {
                ++left;
            } else if(nums[left] == target && nums[right] == target) {
                --right;
            } else if (nums[left] == target) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;

                ++left;
                --right;
            }
        }

        // Count the number of the elements whose is equal to the target
        for (int num : nums) {
            if (num != target) {
                count++;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int removeElement(int[] nums, int val) {
        return solution1(nums, val);
    }
}