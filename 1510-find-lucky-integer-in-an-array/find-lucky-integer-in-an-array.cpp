class Solution {
public:

    // Function used to find the lucky number
    int findLuckyNumber(const std::vector<int>&nums) {
        int result = -1;
        std::unordered_map<int,int>frequency;

        for(int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }

        // Traverse the map and find the maximum value which could be lucky number
        for(const auto&entry:frequency) {
            if(entry.first == entry.second) {
                // std::cout << m.first << " " << m.second << std::endl;
                result = std::max(result, entry.first);
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    int findLucky(vector<int>& arr) {
        return findLuckyNumber(arr);
    }
};