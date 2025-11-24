class Solution { 

    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> result = new ArrayList<Boolean>();
        int prefix = 0;
        for (int num: nums) {
            prefix = ((prefix << 1) + num) % 5;
            result.add(prefix == 0);
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */
}