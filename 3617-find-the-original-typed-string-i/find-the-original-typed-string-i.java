class Solution {

    /**
    *    Function used to find the count of the possible string
    *    @param word
    *    @return int - the count of the possible original strings that alice might have intented to type
    *    @author - Pravin Mhaske
    *    @date   - 01/07/2025
    */
    private int countOfPossibleString(String word) {
        if (word == null || word.isEmpty()) {
            return 0;
        }

        int count = 1; // If the alice has written the word correct

        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) == word.charAt(i-1)) {
                count++;
            }
        }
        return count;
    }

    /*
        Analysis:
        Time complexity  : O(n)
        Space complexity : O(1)
    */

    public int possibleStringCount(String word) {
        return countOfPossibleString(word);
    }
}