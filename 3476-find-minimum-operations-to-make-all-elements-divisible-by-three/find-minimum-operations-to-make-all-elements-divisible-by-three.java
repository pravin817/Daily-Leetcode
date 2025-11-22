class Solution {
    public int minimumOperations(int[] nums) {
        
        int operationCount = 0;

        for (int num : nums) {

            /**
             * Note If we divide the any number by 3 we get the remainder in range of [0,2]

             If the number after division gives the remainder of 1 then we can substract 1 from it to make it divisible by 3.
             If its gives the remainder 2 then add 1 to make it divisible by 3.

             If it gives remainder 0 then no need to add 1 or substract 1
             */
            if ( num % 3 != 0) {
                operationCount++;
            }
        }

        return operationCount;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */
}