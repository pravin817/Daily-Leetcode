class Solution {

    // Brute Force Solution - Simulation
    private int bruteForceSolution(int n) {
        int count = 0;

        for (int num = 1; num <= n; num++) {
            if (num > 999) {
                count++;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    /**
        We can optimsed using the mathematical formula based on the constraint.
        The value of the n is [1, n] and n <= 1_00_000.

        So the total number of the commas between [1, 999] = 0
        and in between the [1_000, 1_00_000] = If we have given n then n - 1_000 + 1;

        We can write this as = n - 999

        Hence 

        if n > 999:
            return n - 999
        else 
            return 0
    
     */

    private int optimizedSolution(int n) {
        if (n > 999) {
            return n - 999;
        } else {
            return 0;
        }
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