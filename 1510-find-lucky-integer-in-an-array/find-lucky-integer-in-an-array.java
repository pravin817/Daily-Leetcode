class Solution {
    // Function used find the lucky integer
    private int findLuckyNumber(int[] nums) {
        int luckyNumber = -1;
        HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>();

        // Update the frequecy of the each number
        for (int num: nums) {
            frequency.put(num, frequency.getOrDefault(num, 0) + 1);
        }

        // CHeck the number that could be lucky number
        for(Integer key : frequency.keySet()) {
            if (key == frequency.get(key)) {
                luckyNumber = key;
            }
        }

        return luckyNumber;        
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    public int findLucky(int[] arr) {
        return findLuckyNumber(arr);
    }
}