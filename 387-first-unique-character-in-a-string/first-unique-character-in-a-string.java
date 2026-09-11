class Solution {

    private boolean isEmpty(String s) {
        return s ==  null || s.isEmpty();
    }

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
            Time Complexity  : O(2n)   -> O(n)
            Space Complexity : O(26)   -> O(1)
    */


    public int firstUniqChar(String s) {
        return solutionUsingArray(s);
    }
}