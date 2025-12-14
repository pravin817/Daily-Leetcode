class Solution {

    private int[] solution(int[] nums, int n) {
        int[] result = new int[2*n];

        for (int i = 0; i < n; ++i) {
            result[2*i] = nums[i];
            result[2*i+1] = nums[i+n];
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    // Solution - 2 By making the change in the input array
    private int[] solution2(int[] nums, int n) {
        int len = nums.length;

        for (int i = n; i < len; i++) {
            nums[i] = (nums[i] * 1024) + nums[i-n];
        }

        int idx = 0;

        for (int i = n; i < len; ++i, idx += 2) {
            nums[idx] = nums[i] % 1024;
            nums[idx + 1] = nums[i] / 1024;
        }

        return nums;
    }
    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    // Function used to print the array elements
    private void printArrayElements(int[] nums) {
        int length = nums.length;

        System.out.println("Printing the array elements :");
        for (int i = 0; i < length; ++i) {
            System.out.println(nums[i]);
        }
        System.out.println("");
    }

    public int[] shuffle(int[] nums, int n) {
        return solution2(nums, n);
    }
}