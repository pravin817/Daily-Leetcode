class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<Integer>();

        for (int idx = 0; idx < words.length; idx++) {
            String word = words[idx];

            if (word.indexOf(x) != -1) {
                result.add(idx);
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
}