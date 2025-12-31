class Solution {

    // Brute Force solution check for the each possible pair
    private int[] bruteForceSolution(int[] nums, int target) {
        for (int i = 0; i < nums.length; ++i) {
            for (int j = 0; j < nums.length; ++j) {
                if(nums[i] + nums[j] == target && i != j) {
                    return new int[]{i, j};
                }
            }
        }

        return new int[]{-1, -1};
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Little bit optimisation
    private int[] solutionTwo(int[] nums, int target) {
        for(int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if(nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1,-1};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Optimised solution - Store the element in hashMap and check if the element (complement = target - currentElement) exist in the hashMap then return the index of the current element along with the index of complement
    private int[] optimisedSolution(int[] nums, int target) {
        Map<Integer, Integer> elementTracker = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; ++i) {
            int complement = target - nums[i];

            if (elementTracker.containsKey(complement)) {
                return new int[] {i, elementTracker.get(complement)};
            }
            elementTracker.put(nums[i], i);
        }

        return new int[]{-1,-1};
    }

    /*  
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int[] twoSum(int[] nums, int target) {
        return optimisedSolution(nums, target);
    }
}