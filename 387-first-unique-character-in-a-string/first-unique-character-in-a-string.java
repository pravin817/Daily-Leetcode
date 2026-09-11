class Solution {

    private boolean isEmpty(String s) {
        return s == null || s.isEmpty();
    }


    /**
     * Brute Force Solution - Double Scan using indexOf and lastIndexOf
     *
     * For each character, find its first and last occurrence in the string.
     * Since we iterate from index 0, indexOf(ch) always equals the current index
     * for the first occurrence. If the first and last occurrence are the same,
     * the character appears exactly once return its index immediately.
     * If no unique character is found, return -1.
     */
    private int bruteForceSolution(String s) {

        if (isEmpty(s)) {
            return -1;
        }

        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            char ch = s.charAt(idx);

            if (s.indexOf(ch) == s.lastIndexOf(ch)) {  // O(n) each
                return idx;
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */


    /**
     * Optimized Solution - Frequency Count using a Fixed-Size Array
     *
     * Since the input is bounded to 26 lowercase English letters, we use a
     * fixed-size integer array to count the frequency of each character.
     * 
     * In the first pass, we build the frequency table.
     * In the second pass, we walk the string in order and return the index 
     * of the first character whose count is exactly 1.
     * If no such character exists, return -1.
     */
    private int solutionUsingArray(String s) {

        if (isEmpty(s)) {
            return -1;
        }

        int[] counts = new int[26];

        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            counts[s.charAt(idx) - 'a']++;
        }

        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            if (counts[s.charAt(idx) - 'a'] == 1) {
                return idx;
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(2n)  -> O(n), Where n is the length of the string
            Space Complexity : O(26)  -> O(1), As input is bounded to 26 lowercase letters
    */


    /**
     * Optimized Solution - Frequency Count using a HashMap
     *
     * Similar two-pass approach as the array solution, but uses a HashMap
     * to store character frequencies. The map can hold at most 26 entries
     * since the input is bounded to lowercase English letters.
     * First pass builds the frequency map; second pass finds the first
     * character with a count of 1 and returns its index.
     * If none found, return -1.
     */
    private int solutionUsingHashMap(String s) {

        if (isEmpty(s)) {
            return -1;
        }

        Map<Character, Integer> counts = new HashMap<>();

        for (int idx = 0; idx < s.length(); idx++) {  // O(n)
            char ch = s.charAt(idx);
            counts.put(ch, counts.getOrDefault(ch, 0) + 1);
        }

        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            if (counts.get(s.charAt(idx)) == 1) {
                return idx;
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(2n)  -> O(n), Where n is the length of the string
            Space Complexity : O(26)  -> O(1), As input is bounded to 26 lowercase letters
    */

    public int firstUniqChar(String s) {
        return solutionUsingArray(s);
    }
}