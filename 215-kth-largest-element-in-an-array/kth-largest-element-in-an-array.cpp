class Solution {
public:

    int solution1(vector<int>&nums, int k){
        int len = nums.size();
        sort(nums.begin(),nums.end());
        return nums[len-k];
    }

    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(logn)
    */    

    int solution2(vector<int>&nums, int k){
        
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int num:nums){
            pq.push(num);

            // check if the size of the minHeap become greater than k
            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
    }

    /*
        Analysis:
        Time Complexity : O(nlogk)
        Space Complexity : O(k)
    */    

    int findKthLargest(vector<int>& nums, int k) {
        return solution2(nums,k);
    }
};