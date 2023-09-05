class Solution {
    private:

    void solution1(vector<int>& nums, int target,vector<int>&ans){
        int n = nums.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return;
                }
            }
        }
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */    

    vector<int> solution2(vector<int> nums, int target){
        int n = nums.size();

        map<int,int>mp;

        for(int i = 0;i<n;i++){
            int remaining = target - nums[i];

            // check if the remaining element present in the map
            if(mp.find(remaining)!=mp.end()){
                return {mp[remaining],i};
            }else{  // if not present then insert it in map
                    mp[nums[i]] = i;
            }
        }

        return {};
    }

    /*
        Analysis:
        Time Complexity : O(n)
        // Space Complexity : O(n)
    */    

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Brute force
        // vector<int>ans;
        // solution1(nums,target,ans);
        // return ans;

        return solution2(nums,target);
    }
};