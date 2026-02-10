class Solution {

    private int bruteForceSolution(int[] nums) {
        int maxiCount = 0;
        Set<Integer> evenSet = new HashSet<Integer>();
        Set<Integer> oddSet = new HashSet<Integer>();

        for (int i = 0; i < nums.length; ++i) {
            for (int j = i + 1; j < nums.length; ++j) {

                evenSet.clear();
                oddSet.clear();

                for (int start = i; start <= j; ++start) {
                    if (nums[start] % 2 == 1) {
                        oddSet.add(nums[start]);
                    } else {
                        evenSet.add(nums[start]);
                    }
                }

                if (oddSet.size() == evenSet.size()) {
                    maxiCount = Math.max(maxiCount, (j - i + 1));
                }
            }
        }

        return maxiCount;
    }

    /*
        Analysis:
            Time Complexity  : O(n^3)
            Space Complexity : O(n)
    */

    private int betterSolution(int[] nums) {
        int maxiCount = 0;
        for (int i = 0; i < nums.length; ++i) {
            Set<Integer> evenSet = new HashSet<Integer>();
            Set<Integer> oddSet = new HashSet<Integer>();

            for (int j = i; j < nums.length; ++j) {
                if (nums[j] % 2 == 1) {
                    oddSet.add(nums[j]);
                } else {
                    evenSet.add(nums[j]);
                }

                if (oddSet.size() == evenSet.size()) {
                    maxiCount = Math.max(maxiCount, (j - i + 1));
                }
            }
        }

        return maxiCount;
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(n)
    */

    public int longestBalanced(int[] nums) {
        return betterSolution(nums);
    }
}