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

    // Better solution - As we don't take the same element twice so instead of starting from 0 each time we can start from i+1
    private int[] betterSolution(int[] nums, int target) {
        int length = nums.length;

        for (int i = 0; i < length; ++i) {
            for (int j = i+1; j < length; ++j) {
                if(nums[i] + nums[j] == target) {
                    return new int[] {i,j};
                }
            }
        }

        // return the -1, -1 if there is no elements whose sum is equal to the target
        return new int[] {-1, -1};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int[] twoSum(int[] nums, int target) {
        return betterSolution(nums, target);
    }
}