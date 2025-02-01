class Solution {
public:

    // Solution : 1 -> Brute Force Solution
    bool solution1(const std::vector<int>&nums) {
        for(int i = 1; i < nums.size();++i) {
            int sum = nums[i] + nums[i-1];
            if(sum % 2 == 0) {
                return false;
            }
        }
        return true;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

    bool isArraySpecial(vector<int>& nums) {
        return solution1(nums);
    }
};