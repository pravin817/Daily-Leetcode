class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>v(n+1,0);

        int duplicate = 0, missing = 0;

        for(int i = 0;i<n;i++){
            v[nums[i]]++;
        }

        // traverse the vector

        for(int i = 1;i<v.size();i++){
            if(v[i] == 0){
                missing = i;
            }

            if(v[i] == 2){
                duplicate = i;
            }
        }

        return {duplicate,missing};


        /*
            Analysis:
            Time Complexity : O(n)
            Space Complexity : O(n)  
        */    
    }
};