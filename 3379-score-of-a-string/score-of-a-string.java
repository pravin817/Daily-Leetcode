class Solution {
    public int scoreOfString(String s) {
        int length = s.length();
        int score = 0;

        for (int idx = 0; idx < length - 1; idx++) {
            score += Math.abs(s.charAt(idx) - s.charAt(idx+1));
        }

        return score;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
}