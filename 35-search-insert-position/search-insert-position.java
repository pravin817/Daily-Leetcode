class Solution {
    public int searchInsert(int[] nums, int target) {
        // This problem is same as to find the lower bound

        int n = nums.length;
        int low = 0;
        int high = n-1;

        int ans = n;

        while(low<=high){
            // find the mid 
            int mid = low + (high - low)/2;

            if(nums[mid]>=target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
}

/*
    Analysis:
    time Complexity : O(logn)
    Sapce Complexity : O(1)
*/    