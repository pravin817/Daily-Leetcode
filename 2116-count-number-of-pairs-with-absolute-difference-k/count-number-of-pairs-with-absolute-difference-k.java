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

    // We can optimised the above solution by using the hashmap
    private int countKDifferenceOptimal(int[] nums, int k) {
        int counter = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int num: nums) {
            counter += map.getOrDefault(-k+num, 0) + map.getOrDefault(k+num, 0);
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