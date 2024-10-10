class Solution {
public:

    // Brute force solution : Gives the TLE 
    int solution1(const std::vector<int>& nums)
    {
        int n = nums.size();
        int maximumWidth = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(nums[j] >= nums[i])
                {
                    int newWidth = j - i;
                    maximumWidth = max(maximumWidth, newWidth);
                }
            }
        }

        return maximumWidth;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */    

    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;

        //
    }
};