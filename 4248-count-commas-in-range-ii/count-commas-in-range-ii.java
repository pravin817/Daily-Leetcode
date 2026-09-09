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
    private long bruteForceSolution(long n) {
        long count = 0;

        for (long num = 1 ; num <= n; num++) {  // O(n)
            long temp = num;

            while(temp >= 1000) {  // O(log n)
                count++;
                temp /= 1000;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity   : O(n log n) - for each of the n numbers, we divide
                               by 1000 until < 1000, which takes O(log n) steps
            Space Complexity : O(1)
    */

    // Note : The above olution will gave the TLE

    /**
     * Optimal Solution - Math
     *
     * Key Insight:
     *   A number gets its k-th comma when it is >= 1000^k.
     *   So for each threshold p = 1000, 1000000, 1000000000, ...,
     *   count how many numbers in [1, n] are >= p.
     *   That count is (n - p + 1) for each valid p.
     *
     * Dry Run:
     *   n = 1,000,000
     *   p = 1000      : count += 1000000 - 1000 + 1    = 999001  (1st comma)
     *   p = 1000000   : count += 1000000 - 1000000 + 1 = 1       (2nd comma)
     *   p = 10^9      : 10^9 > n, loop ends
     *   Total = 999002 
     */
    private long optimalSolution(long n) {
        long p = 1000;
        long count = 0;

        while (p <= n) {
            count += n - p + 1;
            p *= 1000;
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(log n) - the loop runs O(log base 1000 of n) times
                               since p is multiplied by 1000 each iteration.
                               For n <= 10^15, that is at most 5 iterations.
            Space Complexity : O(1)
    */

    public long countCommas(long n) {
        return optimalSolution(n);
    }
}