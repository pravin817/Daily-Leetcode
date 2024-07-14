class Solution {
public:

    void solution1(vector<int>&nums){
        int n = nums.size();

        vector<int>ans;

        // Take all non zero elements in their relative order
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }

        int nz = ans.size();

        // Copy the all the element back to nums
        for(int i = 0;i<nz;i++){
            nums[i] = ans[i];
        }

        // Now append the zero's at the end
        for(int i = nz;i<n;i++){
            nums[i] = 0;
        }
    }

    /*
        Analysis:
        Time Complexity : O(N)+O(K)+O(N-K) ===> O(2N) ==> O(N)
        Space Complexity : O(N), Where N is the number of the non zero elements in an array.
    */    
    
    void moveZeroes(vector<int>& nums) {
        solution1(nums);
    }
};