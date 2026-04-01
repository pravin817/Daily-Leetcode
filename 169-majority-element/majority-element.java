class Solution {

    // Brute Force Solution
    private int solution1(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int majorityElement(int[] nums) {
        return solution1(nums);
    }
}