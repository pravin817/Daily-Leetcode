class Solution {

    // Brute Force solution: Take the pair and calculate the sum. If the sum equals to the target return the index as the numbers array is 1-indexed array
    private int[] twoSumBruteForce(int[] numbers, int target) {

        for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target && i != j) {
                    return new int[] { i + 1, j + 1 };
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

    // Note the above solution gaves the TLE as it tooks O(n^2) time

    // We can optimsed the above solution little bit further based on the fact that we can't use the same number (i.e number at index i twice) to sum equals to the target

    private int[] twoSumSolution2(int[] numbers, int target) {

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
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    /**
     * We can further optimised this solution by using the hashMap. We will keep the track of the element and its index.
    
        We need to find the indices such the numbers[i] + numbers[j] == target.
    
        we can say complement = target - numbers[i];
    
        We will find the complement in the hashMap if we get the complement then we will return the index of the complement + 1 and currentIdx + 1
    */

    private int[] twoSumHashMapBasedSolution(int[] numbers, int target) {

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int idx = 0; idx < numbers.length; idx++) {

            // 1. Find the complement
            int complement = target - numbers[idx];

            // 2. Find the complement is exist in the map
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement) + 1, idx + 1 };
            }

            // Add the number to the map
            map.put(numbers[idx], idx);
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int[] twoSum(int[] numbers, int target) {
        return twoSumHashMapBasedSolution(numbers, target);
    }
}