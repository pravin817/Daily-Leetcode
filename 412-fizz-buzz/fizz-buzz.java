class Solution {

    // Solution - Just iterate the numbers from [1,n] and check the conditions and add the respective word
    private List<String> solution(int n) {
        List<String> result = new ArrayList<String>(n);

        for (int num = 1; num <= n; num++) {  // O(n)

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

    // Solution 2 - Without using the % (Modulo operator).
    // We have observed that the pattern is repeating after some time. Like after 3 iterations we have the Fizz and after 3 and 5 iterations we have the FizzBuzz and after 5 iterations we have the Buzz again

    private List<String> solutionWithModuloOperator(int n) {
        List<String> result = new ArrayList<String>();

        int num = 1, fizz = 0, buzz = 0;

        while(num <= n) {
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
        return solutionWithModuloOperator(n);
    }
}