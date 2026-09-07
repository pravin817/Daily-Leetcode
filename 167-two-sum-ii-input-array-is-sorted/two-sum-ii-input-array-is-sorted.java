class Solution {

    // Brute Force solution: Take the pair and calculate the sum. If the sum equals to the target return the index as the numbers array is 1-indexed array
    private int[] twoSumBruteForce(int[] numbers, int target) {

        for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target && i != j) {
                    return new int[] {i+1, j+1};
                }
            }
        }

        return new int[]{};
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
            for (int j = i+1; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return new int[] {i+1, j+1};
                }
            }
        }

        return new int[]{};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    public int[] twoSum(int[] numbers, int target) {
        return twoSumSolution2(numbers, target);
    }
}