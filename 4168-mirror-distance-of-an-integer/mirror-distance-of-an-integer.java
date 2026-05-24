class Solution {

    private int reverse(int n) {
        int result = 0;
        while(n > 0) {
            int lastDigit = n % 10;
            result = result * 10 + lastDigit;
            n = n / 10;
        }
        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */

    public int mirrorDistance(int n) {
        return Math.abs(n - reverse(n));
    }
}