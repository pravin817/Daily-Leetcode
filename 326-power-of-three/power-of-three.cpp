class Solution {
public:

    // Function used to check if the number is power of 3
    bool solution1(int n) {

        // Base case
        if (n <= 0) {
            return false;
        }

        while(n % 3 == 0) {
           n /= 3;
        }

        return n == 1;
    }

    /*
        Analysis:
        Time Complexity  : O(logn)  ---> log n base 3
        Space Complexity : O(1)
    */

    /*
        Note : The above solution is iterative solution. We can write the recursive solution also.
    */

    bool isPowerOfThreeRec(int n) {

        // Base case 
        if ( n <= 0) {
            return false;
        }

        if( n == 1) {
            return true;
        }

        if (n % 3 != 0) {
            return false;
        }

        return isPowerOfThreeRec(n / 3);
    }

    /*
        Analysis:
        Time Complexity  : O(logn)
        Space Complexity : O(logn)
    */

    bool isPowerOfThree(int n) {
        return isPowerOfThreeRec(n);
    }
};