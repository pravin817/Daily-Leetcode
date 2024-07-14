class Solution {
public:

    void solution1(vector<int>&nums, int k){
        int n = nums.size();

        k = k % n;

        vector<int>ans;

        // Take the elements from the n-k to the n
        for(int i = n-k;i<n;i++){
            ans.push_back(nums[i]);
        }

        // Now take the elements from the start to n-k
        for(int i = 0;i<n-k;i++){
            ans.push_back(nums[i]);
        }

        // Again change the elements in the main array
        for(int i = 0;i<n;i++){
            nums[i] = ans[i];
        }
    }

    /*
        Analysis:
        Time Complexity : O(K) + O(N-K)+ O(N) ===> O(2N)==> O(N)
        Space Complexity : O(N), Where N is the number of the elements in the array
    */    

    void solution2(vector<int>&nums, int k){
        int n = nums.size();

        k = k % n;

        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin(), nums.end());
    }

    /*
        Analysis:
        Time Complexity : O(2N) ==> O(N)
        Space Complexity : O(1)
    */


    void rotate(vector<int>& nums, int k) {
        solution2(nums, k);
    }
};