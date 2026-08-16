class Solution {
    public int nearestDrone(int[][] drones, int[] target) {
        int minimumIdx = Integer.MAX_VALUE;
        int minimumDistance = Integer.MAX_VALUE;
        int currentIdx = 0;

        for (int[] drone : drones) {
            int x1 = drone[0];
            int y1 = drone[1];

            int x2 = target[0];
            int y2 = target[1];

            int range = drone[2];

            int manhattanDistance = Math.abs(x1 - x2) + Math.abs(y1 - y2);

            if (manhattanDistance <= range && manhattanDistance < minimumDistance ) {
                minimumDistance = manhattanDistance;
                minimumIdx = currentIdx;
            }

            ++currentIdx;
        }

        return minimumIdx == Integer.MAX_VALUE ? -1 : minimumIdx;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
}