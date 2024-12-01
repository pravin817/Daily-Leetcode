class Solution {
public:

    // Function that checks if N and its double exist
    bool solution1(const std::vector<int>&nums){
        bool isExist = false;
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(
                       (nums[i] == 2*nums[j])
                    || (nums[j] == 2*nums[i])
                    ){
                    isExist = true;
                    break;
                }
            }
        }

        return isExist;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)    ----> Where N is the number of the elements in the vector
        Space Complexity : O(1)
    */    


    bool checkIfExist(vector<int>& arr) {
        return solution1(arr);
    }
};