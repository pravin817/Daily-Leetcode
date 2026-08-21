class Solution {

    // Function used to check if the string is empty
    private boolean isEmpty(String s) {
        return s == null || s.length() == 0;
    }

    // Function used to reverse the prefix of the string
    public String reversePrefix(String s, int k) {
        
        // Validations
        if (isEmpty(s)) {
            return null;
        }

        // Reverse the prefix of the string
        char[] arr = s.toCharArray();
        int start = 0;
        int end = k - 1;

        while (start < end) {
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            ++start;
            --end;
        }

        return new String(arr);
    }

    /*
        Analysis:
            Time Complexity  : O(k)
            Space Complexity : O(n)
    */
}