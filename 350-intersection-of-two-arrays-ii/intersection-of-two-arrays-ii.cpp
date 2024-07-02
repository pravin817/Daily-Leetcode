class Solution {
public:

    vector<int>solution1(vector<int>&num1, vector<int>&num2){
        vector<int>ans;

        unordered_map<int,int>mp;

        // Insert into the map
        for(auto x:num1){
            mp[x]++;
        }

        // check if it exist in the map for the pair
        for(int x:num2){
            if(mp.find(x)!=mp.end() && mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }

        return ans;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return solution1(nums1, nums2);
    }
};