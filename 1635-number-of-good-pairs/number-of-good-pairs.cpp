class Solution {
public:

    // used the frequency array to store the frequencies of the numbers 
    int solution5(vector<int>nums){
        vector<int>freq(101,0);
        int count = 0;
        
        for(auto num:nums){

            count+=freq[num];
            
            // Update the frequency
            freq[num]++;
        }

        return count;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)  ---> constant (fixed size array/ vector)
    */

    int numIdenticalPairs(vector<int>& nums) {
        return solution5(nums);
    }
};