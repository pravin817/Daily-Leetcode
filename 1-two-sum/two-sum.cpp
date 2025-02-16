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

    // We can optimised the above solution by using the unordered_map
    std::vector<int> findTwoSum2(const std::vector<int>&nums, int target) {
        std::unordered_map<int,int>indexMap;

        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if(indexMap.find(complement)!= indexMap.end()){
                return {indexMap[complement], i};
            } 

            indexMap[nums[i]] = i;
        }

        return {};
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        return findTwoSum2(nums, target);
    }
};