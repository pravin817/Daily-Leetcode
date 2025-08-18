class Solution {
public:

    // Function used to check if the number is power of 3
    bool solution1(int n) {

        // Base case
        if (n <= 0) {
            return false;
        }

        while(n > 0) {
            int remainder = n % 3;

            if (remainder == 0) {
                n = n / 3;
            } else {
                if (n == 1){
                    return true;
                } else {
                    return false;
                }
            }

        }

        return false;
    }

    /*
        Analysis:
        Time Complexity  : O(logn)  ---> log n base 3
        Space Complexity : O(1)
    */



    bool isPowerOfThree(int n) {
        return solution1(n);
    }
};