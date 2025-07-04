class Solution {

    /*
        Function used to return the k the character based on the given problem statement.
        Author - Pravin Mhaske
        Date   - 04/07/2025
    */
    private char getKthCharacter(int k) {
        String originalWord = "a";
        String nextWord = "";

        while(originalWord.length() < k) {
            nextWord = "";

            // Find the next word based on original word
            for(int i = 0; i < originalWord.length(); i++) {
                nextWord += (char)((originalWord.charAt(i) + 1 -'a') % 26 + 'a');
            }

            // update original word
            originalWord = originalWord + nextWord;
        }

        return originalWord.charAt(k-1);
    }

    /*
        Analysis:
        Time Complexity  : O(k)
        Space COmplexity : O(k)
    */

    public char kthCharacter(int k) {
        return getKthCharacter(k);
    }
}