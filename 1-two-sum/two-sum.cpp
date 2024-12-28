class Solution {
public:

    // Solution : 1 -> Brute force solution by trying out all possible pair
    std::vector<int> solution1(const std::vector<int> &nums, int target){
        int n = nums.size();
        std::vector<int> result;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        return solution1(nums, target);
    }
};