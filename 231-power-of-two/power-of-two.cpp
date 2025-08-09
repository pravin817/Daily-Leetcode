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

    bool isPowerOfTwo(int n) {
        return isPowerOfTwoBruteForce(n);
    }
};