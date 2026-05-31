class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];
        int consonant = 0;
        int vowel = 0;

        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            int currentFreq = ++freq[idx];

            switch(ch) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel = Math.max(vowel, currentFreq);
                    break;
                default:
                    consonant = Math.max(consonant, currentFreq);
            }
        }

        return vowel + consonant;
    }

    /*
        Analysis:
            Time Complexity : O(n)
            Space Complexity : O(26) --> O(1)
    */
}