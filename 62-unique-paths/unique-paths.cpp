class Solution {
    private:
    int countPaths1(int i, int j, int m, int n){
        // base case 
        if(i>=n || j >=m){
            return 0;
        }

        // small calculation 
        if(i == (n-1) && j ==(m-1)){
            return 1;
        }

        //Recursive function call
        return countPaths1(i+1,j,m,n) + countPaths1(i,j+1,m,n);
    }

    /*
        Analysis:
        Time Complexity : Exponential
        Space Complexity : Exponential (Stack)
    */    

    // By using the DP 

    int countPaths2(int i, int j, int m, int n,vector<vector<int>>&dp){
        // base case 
        if(i>=n || j >=m){
            return 0;
        }

        // small calculation 
        if(i == (n-1) && j ==(m-1)){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //Recursive function call
        return dp[i][j] = countPaths2(i+1,j,m,n,dp) + countPaths2(i,j+1,m,n,dp);
    }

    /*
        Analysis:
        Time Complexity : O(m*n)
        Space Complexity : O(m*n)
    */    


    int solution3(int m, int n){
        int N = m+n-2;
        int r = m-1;

        double res = 1;

        for(int i = 1;i<=r;i++){
            res = res *(N-r+i)/i;
        }

        return (int)res;
    }
    
    /*
        Analysis:
        Time Complexity : O(m-1)
        Space Complexity : O(1)
    */    

public:
    int uniquePaths(int m, int n) {

        // Brute Force using the recursion
        // return countPaths(0,0,m,n);

        // dp Approach ----> improved Solution
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return countPaths2(0,0,m,n,dp);

        // Optimised Approach
        return solution3(m,n);
    }
};