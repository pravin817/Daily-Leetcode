class Solution {
    public boolean isMonotonic(int[] nums) {
        int n = nums.length;

        boolean Increasing = false;
        boolean Decreasing = false;

        for(int i = 0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                Increasing = true;
            }

            if(nums[i] > nums[i+1]){
                Decreasing = true;
            }            
        }

        return (Increasing && Decreasing) ? false : true;
    }
}

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    