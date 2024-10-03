class Solution {
public:

    // Brute Force solution ---> As there is always the majority element whihc is occurs n / 2 ) then the middle element after the sorting will be always the majority element

    int solution1(vector<int> &nums)
    {
        int n = nums.size();

        // 1. Sort the nums
        sort(nums.begin(), nums.end());

        // 2, return the element at the middle index (mid index)
        int midIdx = n / 2;

        // 3. return the element
        return nums[midIdx];
    }

    /*  
        Analysis:
        Time Complexity : O(NlogN)   ---> Intro sort
        Space Complexity : O(logN)   ---> Internal space for the intro sort
    */    

    // A Better solution would be like the used the map to store the frequency and check if the frequncy is greater than n/2 the return that element and there is always the majority element

    int solution2(const std::vector<int> &nums)
    {
        int n = nums.size();

        std::map<int, int>mp;

        // 1. insert the element in the map and check if the element is the majority lement or not
        for(int i = 0; i < n; ++i)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] > n / 2)
                return nums[i];
        }

        return -1;
    }

    /*
        Analysis:
        Time Complexity : O(NlogK)  ----> Where N is the size of the vector and k is the number of the unique elements in the map
        Space Complexity : O(N)
    */    


        
    int majorityElement(vector<int>& nums) {
        return solution2(nums);
    }
};