class Solution {

    // Solution
    private int getRepeatedNTimesElement(int[] nums) {
        int length = nums.length;
        int n = length / 2;
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        // Add the all elements to the hashMap
        for (int num: nums) {
            hashMap.put(num, hashMap.getOrDefault(num,0) + 1);
        }

        // return the key whose value is greater than 1
        for (int key: hashMap.keySet()) {
            if (hashMap.get(key) > 1) {
                return key;
            }
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