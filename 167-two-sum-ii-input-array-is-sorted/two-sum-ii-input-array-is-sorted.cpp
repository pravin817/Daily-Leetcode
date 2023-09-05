class Solution {
    private:

    // brute force  --- Gives TLE
    vector<int> solution1(vector<int>nums, int target){
        int n = nums.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    return {i+1,j+1};
                }
            }
        }

        // return the empty vector for the compiler 
        return {};
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */

    // As the array is sorted and there is always exactly one solution we can use two pointer appraoch. i.e binary search type

    vector<int> solution2(vector<int>nums, int target){
        int low = 0;
        int high = nums.size()-1;


        while(low<high){

            //check for the target sum 

            int sum = nums[low]+nums[high];

            if(sum == target){
                return {low+1, high+1}; //As the index is 1 based
            }else if( sum > target){
                high--;
            }else{
                low++;
            }
        }

        return {};
    }    

    /*
        Analysis:
        Time Complexity : O(n)
        Space complexity : O(1)
    */    

public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Brute force
        // return solution1(numbers,target);

        // Optimised solution 
        return solution2(numbers, target);
    }
};