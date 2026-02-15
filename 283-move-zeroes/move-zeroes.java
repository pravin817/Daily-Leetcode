class Solution {

    // Brute Force solution
    private int[] solution(int[] nums) {
        int i = 0;
        int [] result = new int[nums.length];

        // Traverse the nums array
        for (int num: nums) {
            if (num != 0) {
                result[i++] = num;
            }
        }

        // Add the all remaining 0
        while (i < nums.length) {
            result[i++] = 0;
        }

        return result;
    } 

    // Function used to print the elements from the array
    private void logElements(int[] nums) {
        for (int num: nums) {
            System.out.println(num);
        }
    }

    // public void moveZeroes(int[] nums) {
    //     int [] result = solution(nums);

    //     for (int i = 0; i < nums.length; ++i) {
    //         nums[i] = result[i];
    //     }
    // }


    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    // Function used to swap the elements of the array
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(1)
    */

    // Optimised solution
    public void moveZeroes(int[] nums) {
        int length = nums.length;
        int start = 0, current = 0;

        while (current < length) {
            if (nums[current] == 0) {
                current++;
                continue;
            }

            swap(nums, current, start);
            start++;
            current++;
        }
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */
}