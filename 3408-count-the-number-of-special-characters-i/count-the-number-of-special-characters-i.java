class Solution {

    private int bruteForceSolution(String word) {
        int[] lowerCaseLetters = new int[26];
        int[] upperCaseLetters = new int[26];
        int count = 0;

        for (int idx = 0; idx < word.length(); idx++) {
            char ch = word.charAt(idx);

            if (ch >= 'a' && ch <= 'z') {
                int newIdx = ch - 'a';
                lowerCaseLetters[newIdx]++;
            } else {
                int newIdx = ch - 'A';
                upperCaseLetters[newIdx]++;
            }
        }

        for (int idx = 0; idx < 26; idx++) {
            if (lowerCaseLetters[idx] > 0 && upperCaseLetters[idx] > 0) {
                count++;
            }
        }

        return count;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Spacd Complexity : O(26) -> O(1)
    */

    public int numberOfSpecialChars(String word) {
        return bruteForceSolution(word);
    }
}