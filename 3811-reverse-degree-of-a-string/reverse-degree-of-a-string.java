class Solution {

    // Function used to check if the string is empty
    private static boolean isEmpty(String s) {
        return s == null || s.length() == 0;
    }

    public int reverseDegree(String s) {
        // Validations
        if (isEmpty(s)) {
            return 0;
        }

        int degree = 0;

        // Calculate the degree using the formula mentioned
        for (int idx = 0; idx < s.length(); idx++) {
            char ch = s.charAt(idx);
            degree += ('z' - ch + 1) * (idx + 1);
        }

        return degree;
    }

    /*
        Analysis:
            Time Complexity  : O(n) , Where n is the total number of the characters in a string
            Space Complexity : O(1)
    */
}