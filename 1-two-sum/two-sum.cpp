class Solution {
public:

    // Check for the each elements in the array
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

    // As the each input has exactly one solution, we can store the elements in map along with their index and find in the map if found then we will return the answer.

    vector<int> solution2(vector<int>&nums, int target)
    {
        int length = nums.size();
        // value -> idx
        std::map<int,int>mp;
        vector<int>result;

        // put the first element
        mp[nums[0]] = 0;

        // now traverse the all elements from the vector
        for(int i = 1; i<length; ++i)
        {
            int valueToBeFind = target - nums[i];
            if(mp.find(valueToBeFind)!=mp.end())
            {
                // If the pair is found then 
                result.push_back(mp[valueToBeFind]);
                result.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(N)
    */    

    vector<int> twoSum(vector<int>& nums, int target) {
        return solution2(nums,target);
    }
};