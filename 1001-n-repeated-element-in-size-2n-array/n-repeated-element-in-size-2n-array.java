class Solution {

    // Solution
    private int getRepeatedNTimesElement(int[] nums) {
        int length = nums.length;
        int n = length / 2;
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        for (int num: nums) {
            if(hashMap.containsKey(num)) {
                return num;
            }

            hashMap.put(num, hashMap.getOrDefault(num,0) + 1);
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int repeatedNTimes(int[] nums) {
        return getRepeatedNTimesElement(nums);
    }
}