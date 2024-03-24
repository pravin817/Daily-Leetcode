class Solution {
public:

    // Brute Force
    int solution1(vector<int>nums){
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return 0;
    }

    /*
        Analysis:
        Time complexity : O(N^2)
        Space Complexity : O(1)
    */

    /*  
        Note : The above solutions gives the TLE
    */


    // Solution - 2 By using the sorting

    int solution2(vector<int>nums){
        int n = nums.size();
        // sort the vector

        sort(nums.begin(),nums.end());

        for(int i = 0;i<n-1;i++){
            if(nums[i] ==nums[i+1]){
                return nums[i];
            }
        }

        return 0;
    }

    /*
        Analysis:
        Time complexity : O(nlogn)
        Space Complexity : O(logn)
    */
        
    int findDuplicate(vector<int>& nums) {
        return solution2(nums);
    }
};