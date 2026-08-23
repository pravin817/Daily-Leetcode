class Solution {

    // Function used to check if the string is empty
    private boolean isEmpty(String s) {
        return s == null || s.isEmpty();
    }

    // Function used to check if the string is palindrome
    private boolean isPalindrome(String s) {
        if (isEmpty(s)) {
            return false;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left)  != s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    // Function used to build the binary string.
    // Assumes ASCII input (each char fits in 8 bits, 0-255).
    private String buildBinaryString(String s) {
        if (isEmpty(s)) {
            return null;
        }

        StringBuilder result = new StringBuilder(s.length() * 8);

        for (int idx = 0; idx < s.length(); idx++) {
            char ch = s.charAt(idx);

            // Append the 8 bits of ch directly, MSB first —
            // avoids repeated string concatenation and guarantees
            // exactly 8 bits per char (no overflow past a byte).
            for (int bit = 7; bit >= 0; bit--) {
                result.append((ch >> bit) & 1);
            }
        }

        return result.toString();
    }
    /*
        Analysis:
            Time Complexity  : O(n)   ==> 8 bits per char, constant work per char
            Space Complexity : O(8*n) ==> O(n)
    */

    public boolean isPalindromic(String s) {
        String binaryStr = buildBinaryString(s);
        return isPalindrome(binaryStr);
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}