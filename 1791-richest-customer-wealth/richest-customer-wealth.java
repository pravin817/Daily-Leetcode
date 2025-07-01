class Solution {

    /**
    * Function used to find the maximum wealth of the customer.
    * @author - Pravin Mhaske
    * @date   - 01/07/2025 
    */

    private int calculateMaximumWealth(int[][] accounts) {
        int maxWealth = 0;

        for(int[] customer: accounts) {
            int currentWealth = 0;

            for(int bank: customer) {
                currentWealth += bank;
            }

            maxWealth = Math.max(maxWealth, currentWealth);
        }

        return maxWealth;
    }

    /*
        Analysis:
        Time complexity  : O(n*m)
        Space complexity : O(1)
    */

    public int maximumWealth(int[][] accounts) {
        return calculateMaximumWealth(accounts);
    }
}