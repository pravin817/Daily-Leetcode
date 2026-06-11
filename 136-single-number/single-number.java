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

    public int singleNumber(int[] nums) {
        return solution1(nums);
    }
}