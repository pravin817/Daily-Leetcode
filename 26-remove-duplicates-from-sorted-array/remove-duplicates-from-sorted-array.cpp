class Solution {
public:

    // Brute Force Solution - As they said to find the uqniue elements whats, come to my mind is set.
    int solution1(vector<int>&nums){
        set<int>s;

        // Insert the elements into the set
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        // Now insert the unique elements back to the array
        int index = 0;
        for(auto it:s){
            nums[index] = it;
            index++;
        }

        return index;
    }

    /*
        Analysis:
        Time Complexity : O(NlogN)+O(N) ==> O(NlogN)
        Space Complexity : O(N) --> Because we have used the set
    */    

    // Optimal Solution - By using the two pointer approach
    int solution2(vector<int>&nums){
        int n = nums.size();
        int i = 0;
        for(int j = 0;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }

    /*
        Analysis:
        Time COmplexity : O(N)
        Space Complexity : O(1)
    */    

    int removeDuplicates(vector<int>& nums) {
        return solution2(nums);
    }
};