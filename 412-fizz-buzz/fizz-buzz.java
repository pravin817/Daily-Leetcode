class Solution {

    /**
        Approach 1 - Modulo check
        Iterate [1, n] and check divisibility conditions in order.
        The combined (% 3 == 0 && % 5 == 0) check must come first
        to ensure "FizzBuzz" is emitted before the individual checks fire.
    */
    private List<String> solutionWithModulo(int n) {
        List<String> result = new ArrayList<String>(n);

        for (int num = 1; num <= n; num++) { // O(n)

            if (num % 3 == 0 && num % 5 == 0) {
                result.add("FizzBuzz");
            } else if (num % 3 == 0) {
                result.add("Fizz");
            } else if (num % 5 == 0) {
                result.add("Buzz");
            } else {
                result.add(String.valueOf(num));
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1), As the result is needed to return  the solution of the problem
    */

    /*
        Approach 2 - Counter (no modulo operator)
        Fizz fires every 3 steps, Buzz every 5, FizzBuzz every 15 (LCM of 3 and 5).
        Two counters replicate this rhythm — when a counter reaches its threshold
        the label is appended and that counter resets to 0.
    */
    private List<String> solutionWithoutModulo(int n) {
        List<String> result = new ArrayList<String>(n);

        int num = 1, fizz = 0, buzz = 0;

        while (num <= n) {
            fizz++;
            buzz++;

            if (fizz == 3 && buzz == 5) {
                result.add("FizzBuzz");
                fizz = 0;
                buzz = 0;
            } else if (fizz == 3) {
                result.add("Fizz");
                fizz = 0;
            } else if (buzz == 5) {
                result.add("Buzz");
                buzz = 0;
            } else {
                result.add(String.valueOf(num));
            }

            num++;
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public List<String> fizzBuzz(int n) {
        return solutionWithoutModulo(n);
    }
}