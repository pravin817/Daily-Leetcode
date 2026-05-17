class Solution {
    public int maxPower(String s) {
        int maxiCount = 0;
        int count = 0;
        char currentChar = ' ';

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == currentChar) {
                count++;
            } else {
                count = 1;
                currentChar = ch;
            }
            maxiCount = Math.max(count, maxiCount);
        }

        return maxiCount;
    }
}

/*
    Analyis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
*/