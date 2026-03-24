class Solution {

    private boolean solution1(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */


    private boolean solution2(int[] nums) {
        Arrays.sort(nums);

        // Check if the adjacent elements are same
        for (int idx = 1; idx < nums.length; idx++) {
            if (nums[idx] == nums[idx-1]) {
                return true;
            }
        }

        return false;
    }
    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */


    private boolean solution3(int[] nums) {
        Map<Integer, Integer> frequencyCount = new HashMap<Integer, Integer>();

        for (int num: nums) {
            if (frequencyCount.containsKey(num)) {
                return true;
            }

            frequencyCount.put(num, frequencyCount.getOrDefault(num, 0)+1);
        }

        return false;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */


    private boolean solution4(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();

        for (int num : nums) {
            if (set.contains(num)) {
                return true;
            }

            set.add(num);
        }

        return false;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    private boolean solution5(int[] nums) {
        return Arrays.stream(nums).distinct().count() < nums.length;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */


    public boolean containsDuplicate(int[] nums) {
        return solution5(nums);
    }
}