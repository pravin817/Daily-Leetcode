class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        if (k == 1) {
            return kadane(nums);
        }
        long res = Long.MIN_VALUE;
        long[] prefix = new long[nums.length + 1];
        for (int i = 1; i <= nums.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < k; i++) {
            int len = (nums.length - i) / k;
            long[] tmp = new long[len];
            for (int j = 0; j < len; j++) {
                int start = i + j * k, end = start + k;
                tmp[j] = prefix[end] - prefix[start];
            }
            res = Math.max(res, kadane(tmp));
        }
        return res;
    }

    static long kadane(long[] nums) {
        long res = Long.MIN_VALUE;
        long curr = 0;

        for (int i = 0; i < nums.length; i++) {
            if (curr + nums[i] > nums[i]) {
                curr += nums[i];
            } else {
                curr = nums[i];
            }
            if (curr > res) {
                res = curr;
            }
        }
        return res;
    }

    private long kadane(int[] nums) {
        long maxSum = Long.MIN_VALUE;
        long currentSum = 0;

        for (int i = 0; i < nums.length; ++i) {
            currentSum += nums[i];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }

            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
}

// CP