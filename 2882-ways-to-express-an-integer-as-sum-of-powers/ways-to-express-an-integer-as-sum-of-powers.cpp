class Solution {
private:
    int M = 1e9+7;
    int dp[301][301];

    int solve(int n, int num, int x) {
        // Base case
        if(n == 0) {
            return 1;
        }

        // Invalide case
        if(n < 0) {
            return 0;
        }

        int currentPowerValue = pow(num, x);
        if (currentPowerValue > n) {
            return 0;
        }

        if(dp[n][num] != -1) {
            return dp[n][num];
        }

        int take = solve(n-currentPowerValue, num + 1, x);
        int skip = solve(n, num + 1, x);

        return dp[n][num] = (take + skip) % M;
    }

    /*
        Analysis:
        Time Complexity  : O(n^2)
        Space Complexity : O(n^2)
    */

public:
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n,1,x);
    }
};