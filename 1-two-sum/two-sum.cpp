class Solution {
public:

    // Solution - 1 : Brute Force solution 
    std::vector<int> findTwoSum(const std::vector<int>&nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }

        return {};
    }

    /*
        Analysis:
        Time Complexity  : O(N^2)
        Space Complexity : O(1)
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        return findTwoSum(nums, target);
    }
};