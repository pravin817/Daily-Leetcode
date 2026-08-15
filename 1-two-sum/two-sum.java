class Solution {

    // Solution - 1 : Brute Force solution by checking the each pair without using the same element twice.
    private int[] solution1(int[] nums, int target) {
        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = 0; jIdx < nums.length; jIdx++) {

                // Check the condition
                if (nums[iIdx] + nums[jIdx] == target && iIdx != jIdx) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        return new int[] {-1, -1};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Coplexity  : O(1)
    */

    // Solution - 2 : Instead of starting the jIdx = 0 we can start the jIdx from iIdx + 1.
    private int[] solution2(int[] nums, int target) {

        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = iIdx + 1; jIdx < nums.length; jIdx++) {

                if (nums[iIdx] + nums[jIdx] == target) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        // If we don't found any pair of elements where sum of two numbers is equal to the target
        return new int[] {-1, -1};
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Solution - 3 : We can keep the track of the element and its index. And find the complement element in the HashMap.
    // Complement = target - nums[idx]
    // Return the idx and the idx of the complement element
    private int[] solution3(int[] nums, int target) {
        Map<Integer, Integer> elementTracker = new HashMap<Integer, Integer>();

        // Step - 1: Put the all elements in the hashMap
        for (int idx = 0; idx < nums.length; idx++) {
            elementTracker.put(nums[idx], idx);
        }

        // Step - 2: Find the complement and return the index of the current and complement element
        for (int idx = 0; idx < nums.length; idx++) {
            int complement = target - nums[idx];

            if (elementTracker.containsKey(complement) && idx != elementTracker.get(complement)) {
                return new int[] {idx, elementTracker.get(complement)};
            }
        }

        // If we don't found any pair of elements where sum of two numbers is equal to the target
        return new int[] {-1, -1}; 
    }
    /*
        Analysis:
            Time Complexity  : O(n) + O(n) = O(2n) => O(n)
            Space Complexity : O(1)
    */

    // Solution - 4 : We can solve this problem statement in single loop
    private int[] solution4(int[] nums, int target) {
        Map<Integer, Integer> elementTracker = new HashMap<Integer, Integer>();

        for (int idx = 0; idx < nums.length; idx++) {
            int complement = target - nums[idx];

            if (elementTracker.containsKey(complement)) {
                return new int[] {idx, elementTracker.get(complement)};
            }

            // Put the element with it's index
            elementTracker.put(nums[idx], idx);
        }

        // Return the {-1, -1} in case of the pair is not found
        return new int[]{-1, -1};
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int[] twoSum(int[] nums, int target) {
        return solution4(nums, target);
    }
}