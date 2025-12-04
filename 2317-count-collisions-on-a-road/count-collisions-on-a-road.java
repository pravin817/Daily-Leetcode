class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        int collisionCount = 0;
    
        // Skip all 'L'
        int i = 0;
        while (i < n && directions.charAt(i) == 'L') {
            ++i;
        }

        // Skip all 'R'
        int j = n -1;
        while (j >= 0 && directions.charAt(j) == 'R') {
            --j;
        }

        // Count the actual collision
        // If directions[i] == 'R' then it will go to collides with someone similary if directions[i] == 'L' then it will gone to collide with someone.
        while (i <= j) {
            if (directions.charAt(i)== 'R' || directions.charAt(i) == 'L') {
                ++collisionCount;
            }
            ++i;
        }

        return collisionCount;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
}