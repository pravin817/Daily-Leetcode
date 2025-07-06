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

    int findLucky(vector<int>& arr) {
        return findLuckyNumber2(arr);
    }
};