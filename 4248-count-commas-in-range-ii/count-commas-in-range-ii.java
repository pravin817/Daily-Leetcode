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
        int count = 0;

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
            Time omplexity   : O(n log n) - for each of the n numbers, we divide
                               by 1000 until < 1000, which takes O(log n) steps
            Space Complexity : O(1)
    */

    // Note : The above olution will gave the TLE

    // Optimal Solution
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
            Time Complexity  : O(log n) , The loop runs O(log base 1000 to n) times because p is multiplied by 1000 in each iteration (at most 5 iterations for n <=10^15).
            Space Complexity : O(1)
    */

    public long countCommas(long n) {
        return optimalSolution(n);
    }
}