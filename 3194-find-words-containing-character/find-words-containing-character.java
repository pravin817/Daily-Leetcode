class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<Integer>();

        for (int idx = 0; idx < words.length; idx++) {
              if (words[idx].indexOf(x) != -1) {
                result.add(idx);
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n*m)  -> Where n is the number of the words and m is the length of the each word
            Space Complexity : O(1)
    */
}