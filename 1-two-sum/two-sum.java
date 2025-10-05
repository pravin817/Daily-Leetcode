class Solution {


    // Function used to find the indices of the elements whose sum equal to target
    private int[] bruteForceSolution(int[] nums, int target) {
        int length = nums.length;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (nums[i] + nums[j] == target && i != j) {
                    return new int[] {i,j};
                }
            }
        }

        return new int[] {-1,-1};

        /*
            Analysis:
                Time Complexity  : O(n^2)
                Space Complexity : O(1)
        */
    }

    public int[] twoSum(int[] nums, int target) {
        return bruteForceSolution(nums, target);
    }
}