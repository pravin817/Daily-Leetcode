class Solution {

    private int solution(int[] nums) {
        
        int largest       = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            } else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        return (largest - 1) * (secondLargest - 1);
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int maxProduct(int[] nums) {
        return solution(nums);
    }
}