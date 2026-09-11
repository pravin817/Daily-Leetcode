class Solution {

    // Solution - Just iterate the numbers from [1,n] and check the conditions and add the respective word
    private List<String> solution(int n) {
        List<String> result = new ArrayList<String>(n);

        for (int num = 1; num <= n; num++) {

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

    public List<String> fizzBuzz(int n) {
        return solution(n);
    }
}