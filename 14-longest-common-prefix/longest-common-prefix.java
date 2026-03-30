class Solution {


    // Brute Force Solution
    private String bruteForceSolution(String[] strs) {

        if (strs.length == 0) {
            return "";
        }

        int prefixLength = 0;

        while(true) {
            if (strs[0].length() > prefixLength) {

                boolean allWell = true;
                char ch = strs[0].charAt(prefixLength);

                for (int i = 1; i < strs.length; ++i) {
                    if (prefixLength < strs[i].length()  && strs[i].charAt(prefixLength) == ch) {
                        // Nothing
                    } else {
                        allWell = false;
                        break;
                    }
                }

                if (allWell) {
                    prefixLength++;
                } else {
                    break;
                }

            } else {
                break;
            }
        }

        return strs[0].substring(0, prefixLength);
    }

    /*
        Analysis:
            Time Complexity  : O(n*m)
            Space Complexity : O(1)
    */

    public String longestCommonPrefix(String[] strs) {
        return bruteForceSolution(strs);
    }
}