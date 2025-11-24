class Solution { 

    public List<Boolean> prefixesDivBy5(int[] nums) {
        ArrayList<Boolean> result = new ArrayList<Boolean>();
        int number = 0;
        for (int num: nums) {

            number = (number * 2 + num) % 5;

            if (number == 0) {
                result.add(true);
            } else {
                result.add(false);
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(1)
    */
}