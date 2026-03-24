class Solution {

    private boolean bruteForceSolution(int[] nums) {
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