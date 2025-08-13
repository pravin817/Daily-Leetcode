class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }

    /*
        Analysis:
        Time Complexity  : O(1)
        Space Complexity : O(1)
    */
};