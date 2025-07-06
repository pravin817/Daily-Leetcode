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
            if (i % 3 == 0 && i % 5 == 0) {
                result.add("FizzBuzz");
            } else if (i % 3 == 0) {
                result.add("Fizz");
            } else if (i % 5 == 0) {
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
        Space Complexity : O(n)
    */

    public List<String> fizzBuzz(int n) {
        return solveFizzBuzz(n);
    }
}