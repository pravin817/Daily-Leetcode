class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int size = 1;
        int maximumEle = nums[0];

        for (int idx = 1; idx < nums.size(); ++idx) {
            if(nums[idx] >= maximumEle) {
                maximumEle = nums[idx];
                ++size;
            }
        }

        return size;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */
};