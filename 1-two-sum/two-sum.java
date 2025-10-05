class Solution {


    // Function used to find the indices of the elements whose sum equal to target
    private int[] bruteForceSolution(int[] nums, int target) {
        int length = nums.length;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (nums[i] + nums[j] == target && i != j) {
                    return new int[] {i,j};
                }
            }
        }

        return new int[] {-1,-1};

        /*
            Analysis:
                Time Complexity  : O(n^2)
                Space Complexity : O(1)
        */
    }

    // Better solution - As we don't take the same element twice so instead of starting from 0 each time we can start from i+1
    private int[] betterSolution(int[] nums, int target) {
        int length = nums.length;

        for (int i = 0; i < length; ++i) {
            for (int j = i+1; j < length; ++j) {
                if(nums[i] + nums[j] == target) {
                    return new int[] {i,j};
                }
            }
        }

        // return the -1, -1 if there is no elements whose sum is equal to the target
        return new int[] {-1, -1};
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(1)
    */

    // We can optimised this solution by using the hashMap
    private int[] optimalSolution(int[] nums, int target) {
        int length = nums.length;

        Map<Integer,Integer> map = new HashMap<Integer, Integer>();

        // Add the element and its index to hashMap
        for(int i = 0; i < length; ++i) {
            map.put(nums[i], i);
        }

        // Traverse the array and check if we get the elements whose sum equals to target
        for (int i = 0; i < length; ++i) {
            int complement = target - nums[i];

            if(map.containsKey(complement) && map.get(complement) != i ) {
                return new int[] {map.get(complement), i};
            }
        }

        return new int[]{};
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    // Instead of the two pass we can solve this in a single pass
    private int[] optimalSolution2(int[] nums, int target) {
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; ++i) {
            int complement = target - nums[i];

            // Check if the complement is present in hashMap
            if(hashMap.containsKey(complement)) {
                return new int[] {i, hashMap.get(complement)};
            }

            // Add the entry to the map
            hashMap.put(nums[i],i);
        }

        return new int[] {};
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public int[] twoSum(int[] nums, int target) {
        return optimalSolution2(nums, target);
    }
}