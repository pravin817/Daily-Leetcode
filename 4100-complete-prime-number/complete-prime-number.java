class Solution {

    // Function used to check if the number is prime
    private boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }

        for (int i = 2; i < num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    // Function used to reverse the number
    private int getReveredNumber(int num) {
        int result = 0;

        while (num > 0) {
            result = (result * 10) + (num % 10);
            num /= 10;
        }

        return result;
    }
    /*
        Analysis:
            Time Complexity  : O(n)  , Where n is the number of the digits in num
            Space Complexity : O(1)
    */

    // Function that returns the prefix[] of the number
    private List<Integer> getPrefix(int num) {
        List<Integer> result = new ArrayList<Integer>();
        int currentNumber = 0;
        num = getReveredNumber(num);

        while (num > 0) {
            int lastDigit = num % 10;
            currentNumber = currentNumber * 10 + lastDigit;
            result.add(currentNumber);
            num /= 10;
        }

        return result;
    }

    // Function that returns the suffix of num
    private List<Integer> getSuffix(int num) {
        List<Integer> result = new ArrayList<Integer>();
        int currentNumber = 0;
        int powerCounter = 0;

        while(num > 0) {
            int lastDigit = num % 10;
            currentNumber = currentNumber + lastDigit * (int) Math.pow(10, powerCounter);
            result.add(currentNumber);
            num /= 10;
            ++powerCounter;
        }

        return result;
    }

    // Function used to print the array
    private void print(List<Integer> nums) {
        System.out.println("Printing the array elements");
        for (int num : nums) {
            System.out.println(num);
        }
        System.out.println("");
    }

    public boolean completePrime(int num) {
        List<Integer> prefix = getPrefix(num);

        // print(prefix);
        for (int n : prefix) {
            if (!isPrime(n)) {
                return false;
            }
        }

        List<Integer> suffix = getSuffix(num);
        // print(suffix);
        for (int n : suffix) {
            if (!isPrime(n)) {
                return false;
            }
        }

        return true;
    }
}