class Solution {
public:

    // custom sorting comparator
    static bool cmp(std::string const &s1,std::string const &s2)
    {
        if((s1+s2) > (s2 + s1))
            return true;

        return false;    
    }

    std::string solution1(std::vector<int>&nums)
    {
        std::vector<std::string>newNums;
        std::string result = "";
        int length = nums.size();

        // 1. Convert the nums to string nums
        for(int i = 0; i < length ; ++i)
            newNums.push_back(std::to_string(static_cast<long long>(nums[i])));

        // 2. Sort the newNums based on the custom sorting
        sort(newNums.begin(),newNums.end(), cmp);

        // 3. Build the string
        for(auto &s:newNums)
            result += s;

        // Handle edge case
        if(result[0] == '0')
            return "0";
            
        // 4. return the string
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(logN)  ---> Internal sorting space complexity
    */    

    string largestNumber(vector<int>& nums) {
        return solution1(nums);
    }
};