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

    // Solution using Math
    private int solution2(int numBottles, int numExchange) {
        return numBottles + ((numBottles - 1) / (numExchange - 1));
    }
    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */

    public int numWaterBottles(int numBottles, int numExchange) {
        return solution2(numBottles, numExchange);
    }
}