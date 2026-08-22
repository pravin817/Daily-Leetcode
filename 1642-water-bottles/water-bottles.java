class Solution {

    // Solution using simulations
    private int solution1(int numBottles, int numExchange) {
        int consumedBottles = numBottles;
        int currentBottles  = numBottles;

        while (currentBottles >= numExchange) {
            int emptyBottles = currentBottles / numExchange;
            consumedBottles += emptyBottles;

            currentBottles = (currentBottles % numExchange) + emptyBottles;
        }

        return consumedBottles;
    }
    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */

    public int numWaterBottles(int numBottles, int numExchange) {
        return solution1(numBottles, numExchange);
    }
}