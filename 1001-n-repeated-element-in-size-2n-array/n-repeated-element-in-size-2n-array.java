class Solution {

    // Brute Force Solution - As the repeated element is repeated more the n. and other elements are unique. We can easily find the repeated element which is repeated more than onces and the other elements (n+1) elements are unique.

    private int solution1(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }

        // As there is always solution exist. But it is good to return -1 if the solution is not exists.
        return -1;
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

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
        return solution1(nums);
    }
}