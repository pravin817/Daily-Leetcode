class Solution {
public:

    /******************************************************************************
    *  Function : moveZeroToEnd
    *  Arguments: std::vector<int>& nums
    *  @returns : std::vector<int>
    *  Purpose  : Moves all zeros to the end of the vector while maintaining the 
    *             order of non-zero elements.
    *  Date     : 01/03/2025
    *  Author   : Pravin Mhaske
    ******************************************************************************/
    std::vector<int> moveZeroToEnd(std::vector<int>&nums) {
        int zeroPosition = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                std::swap(nums[i] , nums[zeroPosition]);
                zeroPosition++;
            }
        }
        return nums;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    // Brute Force solution
    std::vector<int> solution1(std::vector<int>&nums){
        int len = nums.size();

        for(int i = 0; i < len - 1; ++i) {
            if(nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        return moveZeroToEnd(nums);
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    vector<int> applyOperations(vector<int>& nums) {
        return solution1(nums);
    }
};