class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder builder = new StringBuilder(words.length);

        for (String word : words) {     // O(n)
            int weight = 0;

            for (int idx = 0; idx < word.length(); idx++) {   // O(m)
                weight += weights[word.charAt(idx) - 'a'];
            }

            weight = weight % 26;

            char ch = (char) ('z' - weight);
            builder.append(ch);
        }

        return builder.toString();
    }

    /*
        Analysis:
            Time Complexity  : O(n*m)  ==> O(k) , Here k is the total number of characters across all strings in words
            Space Complexity : O(n)
            Auxillary Space  : O(1)
    */
}