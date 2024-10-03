class Solution {
public:

    // Brute Force solution ---> As there is always the majority element whihc is occurs n / 2 ) then the middle element after the sorting will be always the majority element

    int solution1(vector<int> &nums)
    {
        int n = nums.size();

        // 1. Sort the nums
        sort(nums.begin(), nums.end());

        // 2, return the element at the middle index (mid index)
        int midIdx = n / 2;

        // 3. return the element
        return nums[midIdx];
    }

    /*  
        Analysis:
        Time Complexity : O(NlogN)   ---> Intro sort
        Space Complexity : O(logN)   ---> Internal space for the intro sort
    */    

    int majorityElement(vector<int>& nums) {
        return solution1(nums);
    }
};