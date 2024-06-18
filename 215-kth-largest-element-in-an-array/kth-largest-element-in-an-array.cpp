class Solution {
public:

    int solution1(vector<int>&nums, int k){
        int len = nums.size();
        sort(nums.begin(),nums.end());
        return nums[len-k];
    }

    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(logn)
    */    

    int findKthLargest(vector<int>& nums, int k) {
        return solution1(nums,k);
    }
};