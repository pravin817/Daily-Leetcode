class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int i = 0,j = 0;

        while(i<len1 && j< len2){

            // same smallest element is found
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }

        // return -1 indicating no small common element in the arrays
        return -1;
    }
};

/*
    Analysis:
    Time Complexity : O(min(len1,len2))
    Space Complexity : O(1)
*/    