class Solution {

    private List<Integer> bruteForceSolution(String[] words, char x) {
        List<Integer> result = new ArrayList<Integer>();

        for (int idx = 0; idx < words.length; idx++) {
            for (char ch : words[idx].toCharArray()) {
                if (ch == x) {
                    result.add(idx);
                    break;
                }
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n*m)  -> n is the numbers of the words and m is the length of the each word
            Space Complexity : O(1)
    */


    private List<Integer> betterSolution(String[] words, char x) {
        List<Integer> result = new ArrayList<Integer>();

        for (int idx = 0; idx < words.length; idx++) {
            if (words[idx].contains(String.valueOf(x))) {
                result.add(idx);
            }
        }

        return result;
    }
    /*
        Analysis:
            Time Complexity  : O(n*m) -> Where n is the number of the words and m is the length of the each word in words array.
            Space Complexity : O(1)
    */


    private List<Integer> optimalSolution(String[] words, char x) {
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


    public List<Integer> findWordsContaining(String[] words, char x) {
        return optimalSolution(words, x);
    }

}