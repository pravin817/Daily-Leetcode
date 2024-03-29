class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int len1 = nums1.size();
        int len2 = nums2.size();

        int i = 0, j = 0;

        while(i<len1 && j<len2){
            if(nums1[i] == nums2[j]){
                if(ans.empty() || ans[ans.size()-1] !=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }else if(nums1[i]> nums2[j]){
                j++;
            }else{
                i++;
            }
        }

        return ans;
    }
};

/*
    Analysis:
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
*/    