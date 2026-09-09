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

    public int countCommas(int n) {
        return bruteForceSolution(n);
    }

}