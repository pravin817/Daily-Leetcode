class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;

        // Build the num1 and num2
        for(int i = 1; i <= n; ++i) {
            if (i % m != 0) {
                num1 += i;
            } else {
                num2 += i;
            }
        }

        return num1 - num2;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
};