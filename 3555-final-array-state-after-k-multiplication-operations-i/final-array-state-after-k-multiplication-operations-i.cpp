class Solution {
public:

    // Function that returns the index of the minimum element 
    int getMinimumIndex(const std::vector<int>&nums){
        int miniValue = INT_MAX;
        int miniIndex = INT_MAX;
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            if(nums[i] < miniValue){
                miniValue = nums[i];
                miniIndex = i;
            }
        }
        return miniIndex;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k--){

            int index = getMinimumIndex(nums);

            int oldValue = nums[index];
            int newValue = oldValue * multiplier;
            nums[index] = newValue;
        }
        return nums;
    }
    /*
        Analysis:
        Time Complexity : O(klogn)
        Space Complexity : O(1)
    */    
};