class Solution {

    private int solution(int[] nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
        }

        return sum%k;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */

    public int minOperations(int[] nums, int k) {
        return solution(nums, k);
    }
}