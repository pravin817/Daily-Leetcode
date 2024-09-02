class Solution {
public:

    int solution1(vector<int>&nums, int k)
    {
        int ans = 0;
        int length = nums.size();

        long long sum = 0;

        for(int i = 0; i < length ; ++i)
        {
            sum += nums[i];
        }

        while(sum < k){
            k -= sum;
        }

        for(int i = 0; i < length ; ++i)
        {
            if(k < nums[i])
            {
                ans = i;
                break;
            }
            else
            {
                k -= nums[i];
            }
        }
        return ans;
    }
    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */   

    int chalkReplacer(vector<int>& chalk, int k) {
        return solution1(chalk,k);
    }
};