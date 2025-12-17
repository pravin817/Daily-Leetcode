class Solution {

    // Function used to find the maximum profit
    private int findMaxProfit(int[] prices) {
        int maxProfit = 0;

        for (int i = 0; i < prices.length; ++i) {
            for (int j = i+1; j < prices.length; ++j) {
                maxProfit = Math.max(maxProfit, prices[j] - prices[i]);
            }
        }

        return maxProfit;
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Note : The above solution gaves the TLE we need to optimsed the solution.

    private int optimsedSolution(int[] prices) {
        int maxProfit = 0;
        int minimumProfit = Integer.MAX_VALUE;
        int maximumProfit = Integer.MIN_VALUE;
        int n = prices.length;
        int[] minProfitTracker = new int[n];
        int[] maxProfitTracker = new int[n];

        for (int i = 0; i < n; ++i) {
            minimumProfit = Math.min(minimumProfit, prices[i]);
            minProfitTracker[i] = minimumProfit;
        }

        for (int i = n-1; i >= 0; --i) {
            maximumProfit = Math.max(maximumProfit, prices[i]);
            maxProfitTracker[i] = maximumProfit;
        }

        for (int i = 0; i < n; ++i) {
            maxProfit = Math.max(maxProfit, maxProfitTracker[i] - minProfitTracker[i]);
        }

        return maxProfit;
    }

    /*
        Analysis:
            Time Complexity  : O(3n) -> O(n)
            Space Complexity : O(2n) -> O(n)
    */

    public int maxProfit(int[] prices) {
        return optimsedSolution(prices);
    }
}