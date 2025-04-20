class Solution {

    // Function that calculates the minimum number of rabbits in forest
    public int numOfRabbits(int[] rabbits) {
        int totalRabbits = 0;
        HashMap<Integer, Integer> countMap = new HashMap<Integer, Integer>();

        for (int rabbit:rabbits) {
            countMap.put(rabbit, countMap.getOrDefault(rabbit,0)+1);
        }

        for(int key:countMap.keySet()) {
            int groupSize = key + 1;
            int groupNeeded = (int)Math.ceil(countMap.get(key)*1.0 / groupSize * 1.0);
            totalRabbits += groupSize * groupNeeded;
        }
        return totalRabbits;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(N)
    */

    public int numRabbits(int[] answers) {
        return numOfRabbits(answers);
    }
}