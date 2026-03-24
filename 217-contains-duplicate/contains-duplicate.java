class Solution {

    private boolean bruteForceSolution(int[] nums) {
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


    private boolean betterSolution(int[] nums) {
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


    public boolean containsDuplicate(int[] nums) {
        return bruteForceSolution(nums);
    }

}