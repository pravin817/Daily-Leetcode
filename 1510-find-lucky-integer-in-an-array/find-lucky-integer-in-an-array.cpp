class Solution {
private:

    // Function used to find the maximum of the two numbers
    int maximum(int num1, int num2) {
        return num1 > num2 ? num1 : num2;
    }

public:
    /*
        Function    : findLuckyNumber1
        Description : Function used to find the lucky number based on the given problem statement.
        Author      : Pravin Mhaske
        Date        : 05/06/2025
    */
    int findLuckyNumber1(const std::vector<int>& nums) {
        int frequency[501] = {0};

        // Update the frequency of the each number
        for(int num: nums) {
            ++frequency[num];
        }

        // Now check the number whose frequency is equal it itself and it is maximum.
        for( int n = nums.size(); n>0; --n) {
            if(frequency[n] == n) {
                return n;
            }
        }

        return -1;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    // We can also used the unordered_map to store the frequecy of the each number and return the number who has the frequecy equal to the number itself which is largest integer.
    int findLuckyNumber2(const std::vector<int>& nums) {
        int result = -1;
        std::unordered_map<int,int> frequency;

        // Update the frequecy of the each number
        for (const auto& num: nums) {
            ++frequency[num];
        }

        // Now find the lucky number
        for(const auto& entry: frequency) {
            if (entry.first == entry.second) {
                result = maximum(result, entry.first);
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    // Solution by modifying the input array.
    /*
        As we are given the 
        
        Constraints:
            1 <= arr.length <= 500
            1 <= arr[i] <= 500

        Henced the lucky number is always in range [1,500].

        As we know that the numbers are stored in 32 bit.

        1        = 00000000 00000000  00000000 00000001
        (number) = -----------------  -----------------
                 = ( 16 bits )         (16 bits)
                 = (used to store the   used to store the value
                    count)

        We will update the original input array such that it will store the count as well as value.

        Now - 

        How to get the value:

        int value = nums[i] & 65535;
        int idx   = value - 1;
        count     = nums[i] + (1 << 16) // pow(2,16) or 65536

    */

    int findLuckyNumber3(std::vector<int>& nums) {
        int n = nums.size();

        // update the input array
        for(int i = 0; i < n; ++i) {
            int val = nums[i] & 65535;
            if (val <= n) {
                // index
                nums[val - 1] = nums[val - 1] + (1 <<16);
            }
            // nums[i] = (first 16 bits count) (next 16 bit - value)
        }

        // return the lucky number
        for(int val = n; val >= 1; --val) {

            if(nums[val-1] >> 16 == val) {
                return val;
            }
        }

        return -1;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */

    int findLucky(vector<int>& arr) {
        return findLuckyNumber3(arr);
    }
};