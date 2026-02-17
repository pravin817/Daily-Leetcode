class Solution {

    //Brute Force solution
    private int bruteForceSolution(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        return nums[length/2];
    }
    /*
        Analysis:
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
    */

    // Better solution by using the hashMap
    private int betterSolution(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        for (int num: nums) {
            hashMap.put(num, hashMap.getOrDefault(num, 0)+1);
        }

        // Return the elements whose frequency count is n / 2
        int freqCount = n / 2;

        for (Map.Entry<Integer, Integer> pair: hashMap.entrySet()) {
            if (pair.getValue() > freqCount) {
                return pair.getKey();
            }
        }

        return -1;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    // Optimal solution using the Boyer moore algorithms
    private int optimalSolution(int[] nums) {

        // Make the assumption that the first element is the majority element.
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == candidate) {
                ++count;
            } else if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else {
                --count;
            }
        }

        // Now validate the selected element is the majority elements
        // In a case of the n / 2 we have only one majority element
        // for n / 3 = 2 (best case)
        // for n / 4 = 3 (best case)
        // for n / k = (k-1) (best case)

        count = 0;
        for (int num: nums) {
            if (num == candidate) {
                ++count;
            }

            if (count > nums.length / 2) {
                return candidate;
            }
        }

        return -1; // As in the question given there is always the majority element is present
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space complexity : O(1)
    */

    public int majorityElement(int[] nums) {
        return optimalSolution(nums);
    }
}