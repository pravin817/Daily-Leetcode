class Solution {
public:
    bool check(vector<int>& nums) {

        int cnt = 0;
        int n = nums.size();

        for(int i = 1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }

        // check for the first and last element
        if(nums[n-1]>nums[0]){
            cnt++;
        }

        return cnt<=1;
    }
};

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    