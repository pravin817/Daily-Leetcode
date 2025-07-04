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

    // Instead of using the string we have optimised it using the stringBuilder
    private char getKthCharacterOptimisedVersion1(int k) {
        StringBuilder originalWord = new StringBuilder("a");
        StringBuilder nextWord = new StringBuilder();

        while (originalWord.length() < k) {
            nextWord.setLength(0);

            for (int i = 0; i < originalWord.length(); i++) {
                nextWord.append((char)((originalWord.charAt(i) - 'a' + 1 ) % 26 + 'a'));
            }
            originalWord.append(nextWord);
        }
        return originalWord.charAt(k-1);
    }

    /*
        Analysis:
        Time Complexity  : O(k)
        Space Complexity : O(k)
    */

    // We can solve this without using the nextWord string
    private char getKthCharacterOptimisedVersion2(int k) {
        StringBuilder originalWord = new StringBuilder("a");

        while (originalWord.length() < k) {
            int size = originalWord.length();
            for (int i = 0; i < size; i++) {
                originalWord.append((char)((originalWord.charAt(i) - 'a' + 1 ) % 26 + 'a'));
            }
        }
        return originalWord.charAt(k-1);
    }

    /*
        Analysis:
        Time Complexity  : O(k)
        Space Complexity : O(k)
    */

    public char kthCharacter(int k) {
        return getKthCharacterOptimisedVersion2(k);
    }
}