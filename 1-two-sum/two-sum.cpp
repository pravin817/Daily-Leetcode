class Solution {
public:

    // Solution : 1 -> Brute force solution by trying out all possible pair
    std::vector<int> solution1(const std::vector<int> &nums, int target){
        int n = nums.size();
        std::vector<int> result;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
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

    // Better Solution : we can store the elements in the map and find if the complement of the number is found means we got the pair, Here complement means target - nums[i] = element , where element we found in the map

    std::vector<int> solution2(const std::vector<int> &nums, int target){
        int n = nums.size();

        unordered_map<int,int> mp;
        // Element and its index

        for(int i = 0; i < n; ++i){
            int complement = target - nums[i];

            // If the complement is found
            if(mp.find(complement) != mp.end()){
                return {mp[complement],i};
            } else {
                mp.insert({nums[i], i});
            }
        }

        return {};
    }

    /*
        Analysis:
        Time Complexity : O(n)  , If the map is unordered if we used just map (then TC : O(nlogn))
        Space Complexity : O(n)   , Where n is the number of the key-value pair in map
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        return solution2(nums, target);
    }
};