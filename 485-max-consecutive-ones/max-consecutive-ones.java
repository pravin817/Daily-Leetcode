class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maximumResult = 0;
        int currentResult = 0;

        for (int num : nums) {
            if (num == 1) {
                currentResult++;
                maximumResult = Math.max(maximumResult, currentResult);
            } else {
                currentResult = 0;
            }
        }

        return maximumResult;
    }
}

/*
    Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
*/