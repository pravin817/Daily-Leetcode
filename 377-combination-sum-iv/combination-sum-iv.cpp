class Solution {   
public:
    int n;

    // Gives Time Limit Exceeded
    // int solve(int idx, vector<int>&nums,int target){

    //     // check the base case
    //     if(target == 0){
    //         return 1;
    //     }

    //     // Check the index out of the bound
    //     if(idx>=n || target<0){
    //         return 0;
    //     } 

    //     // Explore
    //     int take_idx = solve(0,nums,target-nums[idx]);

    //     int reject_idx = solve(idx+1,nums,target);

    //     return take_idx+reject_idx;
    // }

    /*
        Analysis:
        Time Complexity : Exponential

    */    


    // int dp[201][1001];
    // int solve(int idx, vector<int>&nums,int target){

    //     // check the base case
    //     if(target == 0){
    //         return 1;
    //     }

    //     // Check the index out of the bound
    //     if(idx>=n || target<0){
    //         return 0;
    //     } 

    //     if(dp[idx][target]!=-1){
    //         return dp[idx][target];
    //     }

    //     // Explore
    //     int take_idx = solve(0,nums,target-nums[idx]);

    //     int reject_idx = solve(idx+1,nums,target);

    //     return dp[idx][target] = take_idx+reject_idx;
    // }


    // Solve using the loop

        int dp[201][1001];
    int solve(int idx, vector<int>&nums,int target){

        // check the base case
        if(target == 0){
            return 1;
        }

        // Check the index out of the bound
        if(idx>=n || target<0){
            return 0;
        } 

        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }

        // We will do the exploration using the for loop
        // int take_idx = solve(0,nums,target-nums[idx]);
        // int reject_idx = solve(idx+1,nums,target);

        int result = 0;

        for(int i = idx;i<n;i++){
            int take_i = solve(0,nums,target-nums[i]);
            result+=take_i;
        }

        // return dp[idx][target] = take_idx+reject_idx;
        return dp[idx][target] = result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        memset(dp,-1,sizeof(dp));

        return solve(0,nums,target);
    }
};