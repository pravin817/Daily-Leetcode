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

    // Optimized solution by applying the panalty
    private int solution4(int[] nums) {
        int current = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                current = num;
            }

            count += (current == num) ? 1 : -1;
        }

        return current;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */


    // As the majority Element occures more than n / 2 times then we can choose any element from the nums and check if it counts is greater than n /2
    private int solution5(int[] nums) {
        int n = nums.length;
        Random rand = new Random();

        while(true) {
            int candidate = nums[rand.nextInt(n)];
            int count = 0;

            for (int num : nums) {
                if (candidate == num) {
                    count++;
                }
            }

            if (count > n / 2) {
                return candidate;
            }
        }
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
    public int majorityElement(int[] nums) {
        return solution5(nums);
    }
}