class Solution {

    // Function used to check if the character is vowel or not
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public int maxFreqSum(String s) {
        int[] freqTracker = new int[26];
        int maxConsonantFreq = 0;
        int maxVowelFreq = 0;

        for (int idx = 0; idx < s.length(); idx++) {
            char ch = s.charAt(idx);
            freqTracker[ch - 'a']++;
        }

        // Now get the maximum frequency for the vowel and consonants
        for (int idx = 0; idx < 26; idx++) {
            char currentChar = (char) ('a' + idx);

            if (isVowel(currentChar)) {
                maxVowelFreq = Math.max(maxVowelFreq, freqTracker[idx]);
            } else {
                maxConsonantFreq = Math.max(maxConsonantFreq, freqTracker[idx]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }

    /*
        Analysis:
            Time Complexity : O(n)
            Space Complexity : O(26) --> O(1)
    */
}