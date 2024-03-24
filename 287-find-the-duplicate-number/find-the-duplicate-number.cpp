class Solution {
public:

    // Brute Force
    int solution1(vector<int>nums){
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return 0;
    }

    /*
        Analysis:
        Time complexity : O(N^2)
        Space Complexity : O(1)
    */

    /*  
        Note : The above solutions gives the TLE
    */


    // Solution - 2 By using the sorting

    int solution2(vector<int>nums){
        int n = nums.size();
        // sort the vector

        sort(nums.begin(),nums.end());

        for(int i = 0;i<n-1;i++){
            if(nums[i] ==nums[i+1]){
                return nums[i];
            }
        }

        return 0;
    }

    /*
        Analysis:
        Time complexity : O(nlogn)
        Space Complexity : O(logn)
    */

    // Solution - 3 By using the Map

    int solution3(vector<int>nums){
        map<int,int>mp;

        for(auto n:nums){
            mp[n]++;
        }


        // traverse the map and find the frequncy element whose frequecy is 2
        for(auto m:mp){
            if(m.second >= 2){
                return m.first;
            }
        }

        return 0;
    }

    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(n)
    */    

    // Solution - 4 - By using the slow and fast pointer
    int solution4(vector<int>nums){
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        // start the fast pointer from nums[0];

        fast = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */    

    int findDuplicate(vector<int>& nums) {
        return solution3(nums);
    }
};