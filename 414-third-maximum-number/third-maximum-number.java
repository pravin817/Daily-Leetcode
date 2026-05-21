class Solution {

    private int bruteForceSolution(int[] nums) {

        // All unique elements
        HashSet<Integer> set = new HashSet<Integer>();
        for (int num : nums) {
            set.add(num);
        }

        List<Integer> list = new ArrayList<Integer>();

        for (int s : set) {
            list.add(s);
        }

        // Sort the arrays
        Collections.sort(list);

        if (list.size() < 3) {
            return list.get(list.size() - 1);
        }

        return list.get(list.size() - 3);
    }
    /*
        Analysis:
            Time Complexity : O(nlogn)
            Space COmplexity : O(2n) -> O(n)
    */

    private int betterSolution(int[] nums) {
        int first = Integer.MIN_VALUE, second = Integer.MIN_VALUE, third = Integer.MIN_VALUE;

        for (int num : nums) {

            // Skip the duplicate elements
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third maximum element does not exist then return the maximum number
        return third != Integer.MIN_VALUE ? third : first;
    }

    /*
        Analysis:
            Time Complexity : O(n)
            Space COmplexity : O(1)
    */

    public int thirdMax(int[] nums) {
        return bruteForceSolution(nums);
    }
}