class Solution {

    // Solution - 1: Brute force — check every pair without using the same element twice.
    private int[] solution1(int[] nums, int target) {
        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = 0; jIdx < nums.length; jIdx++) {

                // Check the condition
                if (nums[iIdx] + nums[jIdx] == target && iIdx != jIdx) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        return new int[] {};
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Solution - 2: Instead of starting jIdx at 0, start it from iIdx + 1.
    private int[] solution2(int[] nums, int target) {
        for (int iIdx = 0; iIdx < nums.length; iIdx++) {
            for (int jIdx = iIdx + 1; jIdx < nums.length; jIdx++) {

                if (nums[iIdx] + nums[jIdx] == target) {
                    return new int[] {iIdx, jIdx};
                }
            }
        }

        // If we don't find any pair whose sum equals the target
        return new int[] {};
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Solution - 3: Track each element and its index, then look up the complement in a HashMap.
    // Complement = target - nums[idx]
    // Return the current index and the index of the complement element.
    private int[] solution3(int[] nums, int target) {
        Map<Integer, Integer> elementTracker = new HashMap<>();

        // Step 1: Put all elements in the hashmap.
        for (int idx = 0; idx < nums.length; idx++) {
            elementTracker.put(nums[idx], idx);
        }

        // Step 2: Find the complement and return the current and complement indices.
        for (int idx = 0; idx < nums.length; idx++) {
            int complement = target - nums[idx];

            if (elementTracker.containsKey(complement) && idx != elementTracker.get(complement)) {
                return new int[] {idx, elementTracker.get(complement)};
            }
        }

        // If we don't find any pair whose sum equals the target
        return new int[] {};
    }
    /*
        Analysis:
            Time Complexity  : O(n) + O(n) = O(2n) => O(n)
            Space Complexity : O(n)
    */

    // Solution - 4: Solve it in a single loop.
    private int[] solution4(int[] nums, int target) {
        Map<Integer, Integer> elementTracker = new HashMap<>();

        for (int idx = 0; idx < nums.length; idx++) {
            int complement = target - nums[idx];

            if (elementTracker.containsKey(complement)) {
                return new int[] {idx, elementTracker.get(complement)};
            }

            // Put the element with its index
            elementTracker.put(nums[idx], idx);
        }

        // Return {} if no pair is found
        return new int[] {};
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