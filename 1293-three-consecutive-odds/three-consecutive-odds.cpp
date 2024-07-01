class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len = arr.size();

        if(len<3){
            return false;
        }

        for(int i = 2;i<len;i++){
            if((arr[i]&1) &&(arr[i-1]&1) && (arr[i-2]&1)){
                return true;
            }
        }

        return false;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Complexity : O(1)
*/    