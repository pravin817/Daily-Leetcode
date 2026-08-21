class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder builder = new StringBuilder(words.length);

        for (String word : words) {     // O(n)
            int weight = 0;

            for (int idx = 0; idx < word.length(); idx++) {   // O(m)
                weight += weights[word.charAt(idx) - 'a'];
            }

            weight = weight % 26;

            char ch = (char) ('a' + (25 - weight));
            builder.append(ch);
        }

        return builder.toString();
    }

    /*
        Analysis:
            Time Complexity  : O(n*m)
            Space Complexity : O(n)
    */
}