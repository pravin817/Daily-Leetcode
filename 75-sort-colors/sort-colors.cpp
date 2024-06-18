class Solution {
public:

    void solution1(vector<int>&nums){
        sort(nums.begin(),nums.end());
    }

    /*
        Analysis:
        TC : O(nlogn)
        SC : O(logn)
    */    

    void sortColors(vector<int>& nums) {
        solution1(nums);
    }
};