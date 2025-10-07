class Solution {

    // Function used to solve the given problem
    private int solve(int n, int m) {
        int result = 0;

        for (int counter = 1; counter <= n; ++counter) {
            if (counter % m != 0) {
                result += counter;
            } else {
                result -= counter;
            }
        }

        return result;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int differenceOfSums(int n, int m) {
        return solve(n,m);
    }
}