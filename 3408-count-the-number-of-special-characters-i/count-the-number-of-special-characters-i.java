class Solution {

    private int bruteForceSolution(String word) {
        int[] lowerCaseLetters = new int[26];
        int[] upperCaseLetters = new int[26];
        int count = 0;

        for (int idx = 0; idx < word.length(); idx++) {
            char ch = word.charAt(idx);

            if (ch >= 'a' && ch <= 'z') {
                int newIdx = ch - 'a';
                lowerCaseLetters[newIdx]++;
            } else {
                int newIdx = ch - 'A';
                upperCaseLetters[newIdx]++;
            }
        }

        for (int idx = 0; idx < 26; idx++) {
            if (lowerCaseLetters[idx] > 0 && upperCaseLetters[idx] > 0) {
                count++;
            }
        }

        return count;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Spacd Complexity : O(26) -> O(1)
    */

    private int optimalSolution(String word) {
        Set<Character> hashSet = new HashSet<Character>();
        int count = 0;

        for (char ch : word.toCharArray()) {
            hashSet.add(ch);
        }

        // Check if the pair exist
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (hashSet.contains(ch) && hashSet.contains((char)(ch - 'a' + 'A'))) {
                count++;
            }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(26) -> 0(1)
    */

    public int numberOfSpecialChars(String word) {
        return optimalSolution(word);
    }
}