class Solution {

    // Brute Force Solution
    private int solution1(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // Better Solution using sorting
    private int solution2(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */

    // Better Solution using hashMap
    private int solution3(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> frequencyTracker = new HashMap<Integer, Integer>();

        for (int num : nums) {
            frequencyTracker.put(num, frequencyTracker.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : frequencyTracker.entrySet()) {
            if (entry.getValue() > n / 2) {
                return entry.getKey();
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
        return solution3(nums);
    }
}