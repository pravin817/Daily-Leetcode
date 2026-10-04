class Solution {

    // Function used to calculate the onces in binary representation of the number
    private int countOnces(int n) {
        int count = 0;

        while (n > 0) {
            int lastDigit = n % 2;
            count += lastDigit;
            n /= 2;
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(1)
    */

    // Brute force solution - For each number from [0,n] calculate the number of 1's in binary representations
    private int[] bruteForceSolution(int n) {

        int result[] = new int[n+1];

        for (int num = 0; num <=n; num++) {
            int onesCount = countOnces(num);
            result[num] = onesCount;
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */


    /**
        Optimal solution : We know that the number of 1s in binary representation of 0 is 0

        1    = 001     => 1
        2    = 010     => 1
        3    = 011     => 2
        4    = 100     => 1
        5    = 101     => 2
        6    = 110     => 2
        7    = 111     => 3
        8    =1000     => 1
        9    =1001     => 2
        10   =1010     => 2


        We can find the number of 1s in binary of number based on below formula

        if n is even then number of 1s is same as the number of the 1s in n / 2 else
        number of 1s in n/2 + 1
    
     */

    private int[] optimalSolution(int n) {
        int [] result = new int[n+1];

        if (n == 0) {
            return result;
        }

        result[0] = 0;

        for (int num = 1; num <= n; num++) {

            // num is even
            if (num % 2 == 0) {
                result[num] = result[num / 2];
            } else {
                result[num] = result[num / 2] + 1;
            }
        }

        return result;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public int[] countBits(int n) {
        return optimalSolution(n);
    }
}