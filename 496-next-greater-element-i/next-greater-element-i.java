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
                    for (int k = j + 1; k < nums2.length; k++) {
                        if (nums2[j] < nums2[k]) {
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

        for (int i = 0; i < nums2.length; i++) { // O(m)
            map.put(nums2[i], i);
        }

        // Traverse the nums1
        for (int i = 0; i < nums1.length; i++) { // O(n)

            int target = nums1[i];
            int idx = map.get(target);

            boolean isFound = false;
            while (idx < nums2.length) { // O(m)

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

    private int[] nextGreaterElement(int[] nums) {

        int[] result = new int[nums.length];
        Stack<Integer> st = new Stack<>();

        int n = nums.length;

        int j = n - 1;

        while (j >= 0) {

            while (!st.empty() && st.peek() <= nums[j]) {
                st.pop();
            }

            if (st.empty()) {
                result[j] = -1;
            } else {
                result[j] = st.peek();
            }

            st.push(nums[j]);
            j--;
        }

        return result;
    }

    private int[] nextGreaterElementOptimsedSsolution(int[] nums1, int[] nums2) {

        // Result Array
        int[] result = new int[nums1.length];
        int[] nextGreaterElement = new int[nums2.length];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        // Keep the index of the each element in the hashMap
        for (int idx = 0; idx < nums2.length; idx++) {
            map.put(nums2[idx], idx);
        }

        // Find the next greater element for the each elements in nums2
        // for (int idx = 0; idx < nums2.length; idx++) {
        //     int target = nums2[idx];
        //     boolean isFound = false;

        //     // Find the next greater element
        //     for (int j = idx + 1; j < nums2.length; j++) {
        //         if (nums2[j] > target) {
        //             isFound = true;
        //             break;
        //         }
        //     }

        //     if (isFound) {
        //         nextGreaterElement[idx] = nums2[idx + 1];
        //     } else {
        //         nextGreaterElement[idx] = -1;
        //     }
        // }

        nextGreaterElement = nextGreaterElement(nums2);

        // Find the index
        for (int idx = 0; idx < nums1.length; idx++) {
            int targetIdx = map.get(nums1[idx]);
            result[idx] = nextGreaterElement[targetIdx];
        }

        return result;
    }

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        return nextGreaterElementOptimsedSsolution(nums1, nums2);
    }
}