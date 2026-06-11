class Solution {

    // Track the frequecy for the each element and return the element whose frequecency is one
    private int solution1(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<Integer, Integer>();

        for (int num: nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Find the element whose frequency is one
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() == 1) {
                return entry.getKey();
            }
        }

        return -1; // There is always solution
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */


    // As there is a single element whose frequcency is one and other elements are present exactly two times. We can use XOR here.

    // x ^ 0 = x;
    // x ^ x = 0;

    /*
        |---|---|-----|
        | a | b | a^b |
        |-------------|
        | 0 | 0 |  0  |
        |-------------|
        | 0 | 1 |  1  |
        |-------------|
        | 1 | 0 |  1  |
        |-------------|
        | 1 | 1 |  0  |
        |---|---|-----|
    */
    
    private int solution2(int[] nums) {
        int result = 0;

        for (int num: nums) {
            result = result ^ num;
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity : O(n)
            Space Copelxity : O(1)
    */

    public int singleNumber(int[] nums) {
        return solution2(nums);
    }
}