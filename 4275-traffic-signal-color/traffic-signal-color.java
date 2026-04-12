enum Signal {
    GREEN("Green"),
    ORANGE("Orange"),
    RED("Red"),
    INVALID("Invalid");

    private final String value;

    Signal(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}


class Solution {
    // Brute Force Solution
    private String solution1(int timer) {
        if (timer == 0) {
            return Signal.GREEN.getValue();
        } else if (timer == 30) {
            return Signal.ORANGE.getValue();
        } else if (timer > 30 && timer <= 90) {
            return Signal.RED.getValue();
        } else {
            return Signal.INVALID.getValue();
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