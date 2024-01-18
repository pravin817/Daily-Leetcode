class Solution {
public:

    int solution1(int n){
        // base case
        if(n == 1 || n == 2){
            return n;
        }

        return solution1(n-1) + solution1(n-2);
    }

    /*
        Analysis:
        Time Complexity : O(2^n) exponential
        Space Complexity : O(n)
    */    

    // The above solutions give TLE

    int solution2(int n){
        if(n == 0 || n == 1){
            return 1;
        }

        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-2]+dp[i-1];
        }

        return dp[n];
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(n)
    */


    int solution3(int n){
        if(n == 1 || n ==2){
            return n;
        }

        int a = 1;
        int b = 2;
        int c;

        for(int i = 3;i<=n;i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }    

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */    

    int climbStairs(int n) {
        // return solution1(n);
        // return solution2(n);
        return solution3(n);
    }
};