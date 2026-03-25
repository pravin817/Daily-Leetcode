class Solution {

    // Brute Force Solution
    private boolean solution1(String s, String t) {
        if (s == null || t == null) {
            return false;
        }

        if (s.length() != t.length()) {
            return false;
        }

        int[] freqTracker = new int[26];

        for (int idx = 0; idx < s.length(); ++idx) {
            freqTracker[s.charAt(idx) - 'a']++;
        }

        for (int idx = 0; idx < t.length(); ++idx) {
            freqTracker[t.charAt(idx) - 'a']--;
        }

        for (int idx = 0; idx < 26; ++idx) {
            if (freqTracker[idx] != 0) {
                return false;
            }
        }

        return true;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    // Solution using the hashMap
    private boolean solution2(String s, String t) {
        if (s == null || t == null) {
            return false;
        }

        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> freqTracker = new HashMap<Character, Integer>();

        for (int idx = 0; idx < s.length(); ++idx) {
            freqTracker.put(s.charAt(idx), freqTracker.getOrDefault(s.charAt(idx), 0) + 1);
        }

        for (int idx = 0; idx < t.length(); ++idx) {
            freqTracker.put(t.charAt(idx), freqTracker.getOrDefault(t.charAt(idx), 0) - 1);
        }

        for (Map.Entry<Character, Integer> entry : freqTracker.entrySet()) {
            if (entry.getValue() != 0) {
                return false;
            }
        }

        return true;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space COmplexity : O(1)
    */

    public boolean isAnagram(String s, String t) {
        return solution2(s,t);
    }
}