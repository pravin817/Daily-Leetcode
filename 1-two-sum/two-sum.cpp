class Solution {
public:

    // Brute Force solution : By iterating over the elements from the vector
    std::vector<int> bruteForceSolution(const std::vector<int>&nums, int target) {
        for(int i = 0; i < nums.size(); ++i) {  // O(n)
            for(int j = i+1; j < nums.size(); ++j) { // O(n)
                if(nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    /*
        Analysis:
            Time Complexity : O(n^2)
            Space Complexity : O(1)
    */


    // Solution - 2 : By using the unordered map
    std::vector<int> optimisedSolution(const std::vector<int>&nums, int target) {
        std::unordered_map<int, int> elementWithIndex;

        for (int iElement = 0; iElement < nums.size(); ++iElement) {
            int remaining = target - nums[iElement];

            if (elementWithIndex.find(remaining) != elementWithIndex.end()) {
                return {elementWithIndex[remaining], iElement};
            }

            elementWithIndex[nums[iElement]] = iElement;
        }

        return {-1,-1};
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(n)
    */
    
    vector<int> twoSum(vector<int>& nums, int target) {
        return optimisedSolution(nums, target);
    }
};