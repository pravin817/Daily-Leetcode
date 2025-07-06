class Solution {

    /*
        Function    : solveFizzBuzz
        Description : Function used to solve the Fizz Buzz challenge
        Author      : Pravin Mhaske
        Date        : 06/06/2025
    */

    private List<String> solveFizzBuzz(int n) {
        List<String> result = new LinkedList<String>();

        for (int i = 1; i <= n; ++i) {

            boolean isDivisibleBy3 = i % 3 == 0;
            boolean isDivisibleBy5 = i % 5 == 0;

            if (isDivisibleBy3 && isDivisibleBy5) {
                result.add("FizzBuzz");
            } else if (isDivisibleBy3) {
                result.add("Fizz");
            } else if (isDivisibleBy5) {
                result.add("Buzz");
            } else {
                result.add(String.valueOf(i));
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */

    public List<String> fizzBuzz(int n) {
        return solveFizzBuzz(n);
    }
}