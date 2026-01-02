class Solution {

    // Solution
    private int getRepeatedNTimesElement(int[] nums) {
        int length = nums.length;
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

    // little bit optimsed version of the above solution
    private int getRepeatedElement(int[] nums) {
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        for (int num : nums) {
            if (hashMap.containsKey(num)) {
                return num;
            }

            // Add the element to the hashMap
            hashMap.put(num, hashMap.getOrDefault(num, 0) + 1);
        }

        // It is always we get the solution but it is good practice to return -1 if there is no any solution as the elements from the nums are range from 0 <= nums[i] <= 10^4
        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int repeatedNTimes(int[] nums) {
        return getRepeatedElement(nums);
    }
}