class Solution {
public:

    int indexOfMinimumElement(vector<int>&nums)
    {
        int index = 0;
        int mini = nums[0];
        int numsLength = nums.size();

        for(int i = 0; i < numsLength; ++i)
        {
            if(mini > nums[i])
            {
                mini = nums[i];
                index = i;
            }
        }
        return index;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k)
        {
            int miniElementIndex = indexOfMinimumElement(nums);

            // Update the value at the minimum index
            int previousValue = nums[miniElementIndex];
            int updatedValue = multiplier * previousValue;

            nums[miniElementIndex] = updatedValue;

            --k;
        }

        return nums;    
    }
};

/*
    Analysis:
    Time Complexity : (KlogN)  ----> Where K is the number of the operations, N is the number of the elements in nums.
    Space Complexity : O(1)
*/    