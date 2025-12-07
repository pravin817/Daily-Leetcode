class Solution {
    public int countOdds(int low, int high) {
        int n = high - low + 1;

        if (n % 2 == 0) {
            return n / 2;
        }

        if ( low % 2 == 0 || high % 2 == 0) {
            return n / 2;
        }

        return (n+1) / 2;
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */
}