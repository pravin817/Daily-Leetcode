class Solution {
public:

    // Brute force solution ---> Gives TLE
    vector<int>solution1(vector<int>&nums){
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */    


    // Solution 2 - By using the map
    vector<int>solution2(vector<int>&nums){
        vector<int>ans;
        unordered_map<int,int>mp;

        for(auto n:nums){
            mp[n]++;
        }

        // traverse the map and find the element whose frequency is 2
        for(auto m:mp){
            if(m.second == 2){
                ans.push_back(m.first);
            }
        }

        return ans;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(n)
    */    

    vector<int> findDuplicates(vector<int>& nums) {
        return solution2(nums);
    }
};