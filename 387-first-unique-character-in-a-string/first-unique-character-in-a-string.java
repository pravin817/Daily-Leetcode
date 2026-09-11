class Solution {
    public int firstUniqChar(String s) {
        int[] records = new int[26];

        for (int idx = 0; idx < s.length(); idx++) {  // O(n)
            char ch = s.charAt(idx);
            records[ch - 'a']++;
        }

        // Now traverse the string to find first not repeating character
        for (int idx = 0; idx < s.length(); idx++) {   // O(n)
            char ch = s.charAt(idx);

            if (records[ch - 'a'] == 1) {
                return idx;
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(2n)   -> O(n)
            Space Complexity : O(26)   -> O(1)
    */
}