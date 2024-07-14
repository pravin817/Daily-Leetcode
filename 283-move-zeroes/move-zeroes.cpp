class Solution {
public:


    /*
        This solution is implemented by using the extra space i.e temp array
    */    
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

    // Optimied Solution : By using the two pointer approach

    void solution2(vector<int>&nums){
        int n = nums.size();

        int i = 0;
        for(int j = 0;j<n;j++){
            if(nums[j]!=0){
                nums[i] = nums[j];
                i++;
            }
        }

        // Now insert the zero at the ends
        for(int j = i;j<n;j++){
            nums[j] = 0;
        }
    }

    /*
        Analysis:
        Time Complexity : O(N)+O(N-K) ==> O(N)
        Space Complexity : O(1)
    */    

    void solution3(vector<int>&nums){
        int n = nums.size();

        int j = -1;

        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1){
            return;
        }

        for(int i = j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    
    
    void moveZeroes(vector<int>& nums) {
        solution3(nums);
    }
};