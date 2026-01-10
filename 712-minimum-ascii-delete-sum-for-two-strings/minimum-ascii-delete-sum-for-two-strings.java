class Solution {
    int m, n;
    Integer[][] dp;

    // Function that recursive find the sum of ASCII value of the characters that we need to delete inorder to make the strings equal
    private int solve(int i, int j, String s1, String s2) {
        if (i >= m && j >= n) {
            return 0;
        }

        if (dp[i][j] != null) {
            return dp[i][j];
        }

        if (i >= m) {
            return dp[i][j] = s2.charAt(j) + solve(i, j+1, s1, s2);
        } else if (j >= n) {
            return dp[i][j] = s1.charAt(i) + solve(i+1, j, s1, s2);
        }

        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = solve(i+1, j+1, s1,s2);
        }

        // We have the two possiblities
        int deleteS1I = s1.charAt(i) + solve(i+1, j, s1, s2);
        int deleteS2J = s2.charAt(j) + solve(i, j+1, s1, s2);

        return dp[i][j] = Math.min(deleteS1I, deleteS2J);
    }

    public int minimumDeleteSum(String s1, String s2) {
        m = s1.length();
        n = s2.length();

        // Initialize the array to store the state
        dp = new Integer[m+1][n+1];

        return solve(0, 0, s1, s2);
    }

    /*
        Analysis:
            Without memoization:
                Time Complexity  : O(2^(m+n))  // exponential → TLE
                Space Complexity : O(m+n)      // Recursive Stack

            With memoization:
                Time Complexity  : O(m*n)
                Space Complexity : O(n*m)      // DP Table + Recursive stack
    */
}