// class Solution {
// public:

        // Brute force 
//     void print(vector<int>v){
//         cout<<"Printing the array : ";
//         for(int i = 0;i<v.size();i++){
//             cout<<v[i]<<" ";
//         }
//         cout<<endl;
//     }
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m =nums1.size();
//         int n = nums2.size();

//         vector<int>v(m+n,0);

//         int idx = 0;
//         for(int i = 0;i<m;i++){
//             v[idx] = nums1[i];
//             idx++;
//         }

//         for(int i = 0;i<n;i++){
//             v[idx] = nums2[i];
//             idx++;
//         }

//         sort(v.begin(),v.end());

//         // print(v);
//         int total = v.size();

//         if(total&1){
//             return v[total/2];
//         }else{
//             return ((v[total/2]+v[(total/2) - 1])/2.0);
//         }
//     }
// };

// /*
//     Analysis:
//     Time Complexity : O((m+n)log(m+n))
//     Space Complexity : O(m+n)
// */    


class Solution {
public:

    void print(vector<int>v){
        cout<<"Printing the array : ";
        for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m =nums1.size();
        int n = nums2.size();

        vector<int>v(m+n);

        int idx = 0;
        
        int i = 0;
        int j = 0;
        while(i<m && j <n){
            if(nums1[i] > nums2[j]){
                v[idx++] = nums2[j++]; 
            }else{
                v[idx++] = nums1[i++];
            }
        }

        // Now the remaning of nums1
        while(i<m){
            v[idx++] = nums1[i++];
        }

        // Now the remaining of nums2
        while(j<n){
            v[idx++] = nums2[j++];
        }

        int size = v.size();

        if(size&1){
            return v[size/2];
        }else{
            return (v[size/2] + v[(size/2)-1])/2.0;
        }
    }
};

/*
    Analysis:
    Time Complexity : O(m+n)
    Space Complexity : O(m+n)
*/    