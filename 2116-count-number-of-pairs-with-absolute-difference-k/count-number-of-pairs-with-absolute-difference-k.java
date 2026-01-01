class Solution {

    // Brute Force Solution
    private int countKDifferenceBruteForce(int[] nums, int k) {
        int counter = 0;

        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if(Math.abs(nums[i] - nums[j]) == k) {
                    ++counter;
                }
            }
        }

        return counter;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    /*
        We have given 
            | a - b | = K

            i.e 

            a - b = K   or a - b = -K

            Now find the value of a

            a = b + K   or a = b - K

            Here we want to find a based on the value of b and k as we have already given the k and our b is value from the array.

            hence b = nums[i]

            as we want the count we will store the frequency of the each element and check if we have the a then we add its frequency to the count.

            and update the frequecy of the current element.
    */

    private int countKDifferenceOptimal(int[] nums, int k) {
        int counter = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int num: nums) {
            counter += map.getOrDefault(num - k, 0) + map.getOrDefault(num + k, 0);
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        return counter;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int countKDifference(int[] nums, int k) {
        return countKDifferenceOptimal(nums, k);
    }
}