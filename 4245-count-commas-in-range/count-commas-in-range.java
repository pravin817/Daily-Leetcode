class Solution {

    /**
     * Brute Force Solution - Simulation
     *
     * For each number from 1 to n, count how many commas it contains.
     * A comma is added every 3 digits from the right, so we repeatedly
     * divide by 1000 to count how many comma boundaries exist.
     *
     * Example: 1,000,000 -> divide by 1000 twice -> 2 commas
     */
    private int bruteForceSolution(int n) {
        int count = 0;

        for (int num = 1; num <= n; num++) {
            int temp = num;
            while (temp >= 1000) {
                count++;
                temp /= 1000;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n log n) - for each of the n numbers, we divide
                               by 1000 until < 1000, which takes O(log n) steps
            Space Complexity : O(1)
    */


    /**
     * Optimized Solution - Math
     *
     * Key Observations:
     *   - Numbers in [1, 999]         -> 0 commas each (fewer than 4 digits)
     *   - Numbers in [1000, 99999]    -> 1 comma each  (4 or 5 digits)
     *   - Numbers in [100000, 100000] -> 1 comma        (n is at most 100,000)
     *
     * Since n <= 100,000, every number >= 1000 has exactly 1 comma.
     * So we just need to count how many numbers in [1, n] are >= 1000.
     *
     * Count of such numbers = n - 1000 + 1 = n - 999
     *
     * Dry Run:
     *   n = 1002
     *   Numbers with commas: 1000, 1001, 1002 -> count = 3
     *   Formula: 1002 - 999 = 3 
     *
     *   n = 998
     *   No numbers >= 1000 exist in [1, 998]
     *   Formula: 998 - 999 = -1 -> clamped to 0 
     */
    private int optimizedSolution(int n) {
        return Math.max(0, n - 999);
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */

    public int countCommas(int n) {
        return optimizedSolution(n);
    }

}