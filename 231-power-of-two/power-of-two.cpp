class Solution {
public:

    // This function is used to check if the n is power of two by using the brute force solution.
    bool isPowerOfTwoBruteForce(const int n) {
        if (n <= 0) {
            return false;
        }

        long power = 1;

        while (power <= n) {
            if(power == n) {
                return true;
            }

            power = power * 2;
        }

        return false;
    }

    /*
        Analysis:
        Time Complexity  : O(logn)
        Space Complexity : O(1)
    */

    /*
        Note : As we observed that any number which is power of 2 has only one set bit.
        eg.

        1 =>    0000 0001
        2 =>    0000 0010
        4 =>    0000 0100
        8 =>    0000 1000
        16 =>   0001 0000
        32 =>   0010 0000
        64 =>   0100 0000
        128 =>  1000 0000
    */

    bool isPowerOfTwoBetterSolution(int n) {
        if (n <= 0) {
            return false;
        }

        bool isSetBitFound = false;
        while (n > 0) {
            if (n & 1) {
                if (isSetBitFound) {
                    return false;
                }
                isSetBitFound = true;
            }

            n = n >> 1;
        }

        return true;
    }

    /*
        Analysis:
        Time Complexity  : O(logn)
        Space Complexity : O(1)
    */

    bool isPowerOfTwo(int n) {
        return isPowerOfTwoBetterSolution(n);
    }
};