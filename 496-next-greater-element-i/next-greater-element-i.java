class Solution {

    // Brute Force Solution
    public int[] nextGreaterElementBruteForce(int[] nums1, int[] nums2) {

        // Result Array
        int[] result = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i] == nums2[j]) {
                    // Same element found

                    boolean hasNextGreaterElement = false;
                    for (int k = j+1; k < nums2.length; k++) {
                        if (nums2[j] < nums2[k])  {
                            result[i] = nums2[k];
                            hasNextGreaterElement = true;
                            break;
                        }
                    }

                    if (!hasNextGreaterElement) {
                        result[i] = -1;
                    }
                }
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n^3)
            Space Complexity : O(1)
    */

    // Better Solution using the Map
    private int[] nextGreaterElementBetterSolution(int[] nums1, int[] nums2) {

        // Result Array 
        int[] result = new int[nums1.length];

        // Store the Index of the each element
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums2.length; i++) {  // O(m)
            map.put(nums2[i] , i);
        }

        // Traverse the nums1
        for (int i = 0; i < nums1.length; i++) {  // O(n)

            int target = nums1[i];
            int idx = map.get(target);

            boolean isFound = false; 
            while (idx < nums2.length) {   // O(m)

                if (nums2[idx] > target) {
                    isFound = true;
                    break;
                }

                idx++;
            }

            if (isFound) {
                result[i] = nums2[idx];
            } else {
                result[i] = -1;
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity : O(m) + O(n*m) =>O(n*m)
            Space Complexity : O(n)
    */

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        return nextGreaterElementBetterSolution(nums1, nums2);
    }
}