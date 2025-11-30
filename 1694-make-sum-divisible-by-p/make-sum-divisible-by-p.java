class Solution {

    private int solution1(int[] nums, int p) {
        int n = nums.length;
        long totalSum = 0;

        // Find the total sum
        for (int num : nums) {
            totalSum += num;
        }

        long target = totalSum % p;

        if (target == 0) {
            return 0;
        }

        int minLength = n;

        for (int start = 0; start < n; ++start) {
            long subSum = 0;

            for (int end = start ; end < n; ++end) {
                subSum += nums[end];

                long remainingSum = (totalSum - subSum) % p;

                if (remainingSum  == 0) {
                    minLength = Math.min(minLength, end - start + 1);
                }
            }
        }
        
        return minLength == n ? -1 : minLength;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    private int solution2(int[] nums, int p) {
        int totalSum = 0;
        int n = nums.length;

        Map<Integer, Integer> modMap = new HashMap<Integer, Integer>();

        // Find the total sum
        for (int num : nums) {
            totalSum = (totalSum + num ) % p;
        }

        // Get the target
        int target = totalSum % p;

        if (target == 0) {
            return 0;
        }

        modMap.put(0,-1);

        int minLength = n;
        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i] ) % p;

            int needed = (prefixSum - target + p) % p;

            if(modMap.containsKey(needed)) {
                minLength = Math.min(minLength, i - modMap.get(needed));
            }

            modMap.put(prefixSum, i);
        }

        return (minLength == n) ? -1 : minLength;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int minSubarray(int[] nums, int p) {
        return solution2(nums, p);
    }
}