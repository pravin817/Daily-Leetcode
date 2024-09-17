class Solution {
public:

    vector<int> solution1(vector<int>&nums, int target)
    {
        vector<int>result;
        int length = nums.size();

        for(int i = 0; i < length ; ++i)
        {
            for(int j = i+1; j < length ; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */    

    vector<int> twoSum(vector<int>& nums, int target) {
        return solution1(nums,target);
    }
};