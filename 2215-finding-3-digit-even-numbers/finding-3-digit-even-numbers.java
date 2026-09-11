class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> seen = new HashSet<Integer>();
        int n = digits.length;

        for (int h = 0; h < n; h++) {

            if (digits[h] == 0) {
                continue;
            }

            for (int t = 0; t < n; t++) {
                if (h == t) {
                    continue;
                }


                for (int u = 0; u < n; u++) {
                    if (h == u || t == u || digits[u] % 2 != 0) {
                        continue;
                    }

                    // Form the number
                    int num = digits[h] * 100 + digits[t] * 10 + digits[u];
                    seen.add(num);
                }
            }
        }

        return seen.stream()
                    .mapToInt(Integer::intValue)
                    .sorted()
                    .toArray();

    }

    /*
        Analysis:
            Time Complexity  : O(n^3)
            Space Complexity : O(n)
    */
}