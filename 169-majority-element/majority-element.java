class Solution {

    //Brute Force solution
    private int bruteForceSolution(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        return nums[length/2];
    }
    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */

    // Better solution by using the hashMap
    private int betterSolution(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        for (int num: nums) {
            hashMap.put(num, hashMap.getOrDefault(num, 0)+1);
        }

        // Return the elements whose frequency count is n / 2
        int freqCount = n / 2;

        for (Map.Entry<Integer, Integer> pair: hashMap.entrySet()) {
            if (pair.getValue() > freqCount) {
                return pair.getKey();
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int majorityElement(int[] nums) {
        return betterSolution(nums);
    }
}