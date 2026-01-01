class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Means the digit is 9 then make the digits[i] = 0
            digits[i] = 0;
        }

        // If we reached here meaning the elements are like 9 9 9 9

        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}