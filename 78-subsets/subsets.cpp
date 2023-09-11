class Solution {
    private:

    void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans){

        // base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        // Two cases include or not include ---> exclude
        //Exclude -- just increase the index
        solve(nums,output,index+1,ans);

        // Include the element 
        int ele = nums[index];
        output.push_back(ele);
        solve(nums,output,index+1,ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;

        solve(nums,output,0,ans);
        return ans;
    }
};