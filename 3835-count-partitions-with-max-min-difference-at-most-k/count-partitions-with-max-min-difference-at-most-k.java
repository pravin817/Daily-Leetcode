class Solution {

    private static final long MOD = (long) 1e9 + 7;

    public int countPartitions(int[] nums, int k) {
        
        int n = nums.length;

        long[] dp = new long[n+1];
        long[] prefix = new long[n+1];

        // Deque for the storing the maximum and minimum elements
        Deque<Integer> minQ = new LinkedList<>();
        Deque<Integer> maxQ = new LinkedList<>();

        // Initial States
        dp[0] = 1;
        prefix[0] = 1;

        int left  = 0;

        for (int right = 0; right < n; ++right) {

            // maintain maximum value deque
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] <= nums[right]) {
                maxQ.pollLast();
            }

            maxQ.offerLast(right);

            // Maintaon mimimum value deque
            while (!minQ.isEmpty() && nums[minQ.peekLast()] >= nums[right]) {
                minQ.pollLast();
            }
            
            minQ.offerLast(right);

            while (!maxQ.isEmpty() &&
                   !minQ.isEmpty() &&
                   nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > k) {

                    if (maxQ.peekFirst() == left) {
                        maxQ.pollFirst();
                    }

                    if (minQ.peekFirst() == left) {
                        minQ.pollFirst();
                    }

                    left++;
            }

            dp[right + 1] = (prefix[right] - (left > 0 ? prefix[left - 1] : 0) + MOD) % MOD;

            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
        }

        return (int) dp[n];
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}