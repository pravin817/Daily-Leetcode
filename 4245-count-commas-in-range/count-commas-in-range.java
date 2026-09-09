class Solution {
    public int countCommas(int n) {
        if (n <= 999) {
            return 0;
        }

        return (n - 1_000) + 1;
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */
}