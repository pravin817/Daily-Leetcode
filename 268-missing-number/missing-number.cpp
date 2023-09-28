class Solution {
public:

    // Brute force by using the sum
    int solution1(vector<int> &nums){
        int n = nums.size();
        int sum = 0;
        sum = n*(n+1)/2;

        for(auto i : nums){
            sum -=i;
        }

        return sum;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */

    // We can use the XOR (^) operator
    // We know that the properties of XOR
    // x ^ 0 = X;
    // x ^ (y ^ z) = (x ^ y) ^ z;
    // x ^ x = 0;

    int solution2(vector<int>&nums){
        int i = 1;
        int ans = 0;

        for(auto x : nums){
            ans = ans ^ x;
            ans = ans ^ i;
            i++;
        }

        return ans;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */ 

    int missingNumber(vector<int>& nums) {
        return solution2(nums);
    }
};
