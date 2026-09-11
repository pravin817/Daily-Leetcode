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

        // Convert to an array sorted in ascending order
        List<Integer> res = new ArrayList<>(seen);

        // Sort the ArrayList
        Collections.sort(res);     // O(nlogn)

        // Now return the int[]
        int[] result = new int[res.size()];

        for (int idx = 0; idx < res.size(); idx++) {    // O(n)
            result[idx] = res.get(idx);
        }

        return result;

        // Same as above using stream API
        // return seen.stream()
        //             .mapToInt(Integer::intValue)
        //             .sorted()
        //             .toArray();

    }

    /*
        Analysis:
            Time Complexity  : O(n^3 + M log M)
            Space Complexity : O(M)

            Here M = min(n^3 , 10^k) be the number of even numbers that meet the requirements,
            where n is the length of the input array and k is the number of the digits in the target even number
    */
}