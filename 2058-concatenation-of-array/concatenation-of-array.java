class Solution {
    public int[] getConcatenation(int[] nums) {

        int idx = 0;
        int n = nums.length;
        int[] result = new int[n * 2];

        for (int num : nums) {
            result[idx] = num;
            result[idx+n] = num;
            idx++;
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}