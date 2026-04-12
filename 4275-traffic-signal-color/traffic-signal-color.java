class Solution {

    // Brute Force Solution
    private String solution1(int timer) {
        if (timer == 0) {
            return "Green";
        } else if (timer == 30) {
            return "Orange";
        } else if (timer > 30 && timer <= 90) {
            return "Red";
        } else {
            return "Invalid";
        }
    }
    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */

    public String trafficSignal(int timer) {
        return solution1(timer);
    }
}