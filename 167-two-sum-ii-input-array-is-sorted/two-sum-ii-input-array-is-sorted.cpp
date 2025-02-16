class Solution {
public:

    // Brute Force Solution by using the nested for loops
    std::vector<int> solution1(const std::vector<int>&nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(nums[i] + nums[j] == target) {
                    return {i+1, j+1};  // As the index are 1 based
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

    // Solution : 2 We can optimised the above solution (The above solution gives the TLE) by using the map who can keep the track of the element that we need for the 2 sum
    std::vector<int> solution2(const std::vector<int>&nums, int target) {
        int n = nums.size();
        std::unordered_map<int,int> indexMap;

        for(int i = 0; i < n; ++i){
            int remaining = target - nums[i];
            // Check if the remaining is present in the map
            if(indexMap.find(remaining) != indexMap.end()) {
                return {indexMap[remaining] + 1, i+1}; // As the index is 1 based
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(N)
    */

    vector<int> twoSum(vector<int>& numbers, int target) {
        return solution2(numbers, target);
    }
};