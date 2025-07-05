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

    // We can use the array / hash map as the size of the input is 500 
    int findLuckyNumber2(const std::vector<int>&nums) {
        int store[501] = {};

        for(auto n: nums) {
            ++store[n];
        }

        for(auto n = nums.size(); n > 0; --n) {
            if (n == store[n]) {
                return n;
            }
        }

        return -1;
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    int findLucky(vector<int>& arr) {
        return findLuckyNumber2(arr);
    }
};