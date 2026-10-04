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

    public int[] countBits(int n) {
        return bruteForceSolution(n);
    }
}