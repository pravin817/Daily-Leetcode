class Solution {
public:
    vector<int> solution1 (const std::vector<int>&nums){
        int n = nums.size();
        vector<int>result;
        for(int index = 0; index < n; ++index){
            int discount = 0;
            for(int jIndex = index + 1; jIndex < n; ++jIndex){
                if(nums[index] >= nums[jIndex]){
                    discount = nums[jIndex];
                    break;
                }
            }

            result.push_back(nums[index] - discount);
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1) , if we ignore the result space
    */    

    vector<int> finalPrices(vector<int>& prices) {
        return solution1(prices);
    }
};