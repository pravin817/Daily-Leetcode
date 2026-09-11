class Solution {

    private Set<Integer> getThreeDigitEvenNumber(int[] digits) {
        int n = digits.length;
        Set<Integer> result = new HashSet<Integer>();
        boolean [] visited = new boolean[1000];

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                for (int k = 0; k < n; k++) {
                    if (i == k || j == k || digits[k] % 2 != 0) {
                        continue;
                    }

                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];

                    if (!visited[number]) {
                        visited[number] = true;
                        result.add(number);
                    }
                }
            }
        }

        return result;
    }

    /*
        Analsis:
            Time Complexity  : O(n^3)
            Space Complexity : O(2n)   -> O(n)
    */


    public int totalNumbers(int[] digits) {
        Set<Integer> uniqueNumbers = getThreeDigitEvenNumber(digits);
        return uniqueNumbers.size();
    }
}