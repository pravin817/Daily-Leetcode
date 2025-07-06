class Solution {
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

    int findLucky(vector<int>& arr) {
        return findLuckyNumber1(arr);
    }
};