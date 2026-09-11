class Solution {

    private boolean isEmpty(String s) {
        return s ==  null || s.isEmpty();
    }


    // Brute force solution - Find the first index and last index of the character if both same then this is unique character from the string. In string there could be multiple unique character we need to return the firt one.

    private int bruteForceSolution(String s) {

        // If the string is null or empty then return the -1
        if (isEmpty(s)) {
            return -1;
        }

        for (int idx = 0; idx < s.length(); idx++) {   //O(n)
            char ch = s.charAt(idx);

            int firstIdx = s.indexOf(ch);             // O(n)
            int lastIdx  = s.lastIndexOf(ch);         // O(n)

            // First unique element (As we are starting from 0th index)
            if (firstIdx == lastIdx) {
                return idx;
            }
        }

        // If the given string does not contains the unique character
        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */



    // Solution using the Array
    private int solutionUsingArray(String s) {
        if (isEmpty(s)) {
            return -1;
        }

        int[] counts = new int[26];

        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            char ch = s.charAt(idx);

            // Increase the count of each character
            counts[ch - 'a']++;
        }

        // Find the first non repeating character means unique character
        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            char ch = s.charAt(idx);

            if (counts[ch - 'a'] == 1) {
                return idx;
            }
        }

        // if there is no any unique character then return -1
        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(2n)   -> O(n), Where n is the length of the string
            Space Complexity : O(26)   -> O(1)
    */


    // Solution using the HashMap
    private int solutionUsingHashMap(String s) {
        if (isEmpty(s)) {
            return -1;
        }

        Map<Character, Integer> counts = new HashMap<Character, Integer>();

        for (int idx = 0; idx < s.length(); idx++) {  // O(n)
            char ch = s.charAt(idx);
            counts.put(ch, counts.getOrDefault(ch, 0) + 1);
        }

        // Get the unique character
        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            if (counts.get(s.charAt(idx)) == 1) {
                return idx;
            }
        }

        // If there is no any unique character in the string return -1
        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(2n)   -> O(n) , Where n is the length of the string
            Space Complexity : O(26)   -> O(1)
    */

    public int firstUniqChar(String s) {
        return bruteForceSolution(s);
    }
}