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

    // Optimal Solution by using the Boyer moore algorithms
    int solution3(const std::vector<int> &nums)
    {
        int n = nums.size();
        int candidate = 0;
        int count = 0;

        // 1. Assumption : find the element that may be majority element
        for(int i = 0; i < n; ++i)
        {
            int currentElement = nums[i];

            if(count == 0)
            {
                count = 1;
                candidate = currentElement;
            }
            else if(currentElement == candidate)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        // return candiate; // In this case the answer will the candiate because it is assuered that there is always the majority of the element is there.

        // 2. Validation : Check if the candiate is the majority of the element
        count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == candidate)
                ++count;

            if(count > n / 2)
                return candidate;    
        }

        return -1; // If the no majority element is not found // Here there is no need 
    } 

    /*
        Analysis:
        Time Complexity : O(N)
        Space complexity : O(1)
    */


    int majorityElement(vector<int>& nums) {
        return solution3(nums);
    }
};