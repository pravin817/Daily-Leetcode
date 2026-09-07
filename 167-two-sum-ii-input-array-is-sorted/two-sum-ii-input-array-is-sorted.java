class Solution {

    /**
     * Approach 1: Brute Force
     *
     * Take every pair (i, j) where i < j and check if their sum equals the target.
     * Since the array is 1-indexed, return i + 1 and j + 1.
     */
    private int[] twoSumBruteForce(int[] numbers, int target) {

        for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target && i < j) {
                    return new int[] { i + 1, j + 1 };
                }
            }
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2) - two nested loops over the array
            Space Complexity : O(1)   - no extra space used
    */

    // Note: The above solution gives TLE.

    /**
     * Approach 2: Optimised Brute Force
     *
     * We can optimise Approach 1 slightly by starting the inner loop at i + 1
     * instead of 0. This avoids redundant pairs and removes the need for the
     * i < j guard, since the loop structure enforces it naturally.
     */
    private int[] twoSumOptimisedBruteForce(int[] numbers, int target) {

        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return new int[] { i + 1, j + 1 };
                }
            }
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2) - still two nested loops, but roughly half the work
            Space Complexity : O(1)   - no extra space used
    */

    /**
     * Approach 3: HashMap
     *
     * We can optimise further by using a HashMap to track each element and its index.
     *
     * For each element at index idx, we compute:
     *   complement = target - numbers[idx]
     *
     * If the complement already exists in the map, we have found our pair.
     * Otherwise, we store the current element and its index in the map.
     *
     * Note: This approach is adapted from the classic unsorted Two Sum (LC #1).
     * It works correctly here but uses O(n) space, which violates this problem's
     * constant space requirement. It is included only to show the thought progression.
     */
    private int[] twoSumHashMap(int[] numbers, int target) {

        Map<Integer, Integer> map = new HashMap<>();

        for (int idx = 0; idx < numbers.length; idx++) {

            int complement = target - numbers[idx];

            if (map.containsKey(complement)) {
                return new int[] { map.get(complement) + 1, idx + 1 };
            }

            map.put(numbers[idx], idx);
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n) - single pass through the array
            Space Complexity : O(n) - HashMap stores up to n elements
     */

    /**
     * Approach 4: Two Pointers (Optimal)
     *
     * We can optimise further by exploiting the fact that the array is sorted
     * in non-decreasing order.
     *
     * Place one pointer at the start (left) and one at the end (right).
     * At each step, compute the sum of the two pointed elements:
     *   - If the sum equals the target, return the indices.
     *   - If the sum is less than the target, move the left pointer right to increase the sum.
     *   - If the sum is greater than the target, move the right pointer left to decrease the sum.
     */
    private int[] twoSumTwoPointers(int[] numbers, int target) {

        int left  = 0;
        int right = numbers.length - 1;

        while (left < right) {

            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return new int[] { left + 1, right + 1 };
            } else if (currentSum < target) {
                left++;  // need a larger sum; move left pointer right
            } else {
                right--; // need a smaller sum; move right pointer left
            }
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n) - each pointer moves at most n steps in total
            Space Complexity : O(1) - no extra space used
     */

    public int[] twoSum(int[] numbers, int target) {
        return twoSumTwoPointers(numbers, target);
    }
}