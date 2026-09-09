class Solution {
    public int countCommas(int n) {
        return (n > 999) ? ( n - 999) : 0;
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */
}