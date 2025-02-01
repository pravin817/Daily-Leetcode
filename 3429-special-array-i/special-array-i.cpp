class Solution {
public:

    // Solution : 1 -> Brute Force Solution using the sum of the two numbers
    // Odd Number  (1) + Odd Number (3)  = Even Number (4)
    // Even Number (2) + Even Number(4)  = Even Number (6)
    // Odd Number  (1) + Even Number(2)  = Odd Number  (3)
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
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    /*
        Solution 2 By using the modulo operator (%)
        When number % 2 == 0, Means the number is even number
             number % 2 == 1, Means the number is odd number
    */

    bool solution2(const std::vector<int>&nums) {
        for(int index = 0; index < nums.size() - 1; ++index) {
            if(nums[index] % 2 == nums[index+1] % 2) {
                return false;
            }
        }
        return true;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    /*
        Solution 3 : By using the & operator
            Number & 1 = 1 (Odd Number)
            Number & 1 = 0 (Even Number)
    */
    bool solution3(const std::vector<int>&nums) {
        for(int index = 0; index < nums.size() -1 ; ++index) {
            if((nums[index] & 1) ^ (nums[index+1] & 1) == 0) {
                return false;
            }
        }
        return true;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    bool isArraySpecial(vector<int>& nums) {
        return solution3(nums);
    }
};