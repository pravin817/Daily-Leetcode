class Solution {
public:

    void solution1(vector<int>&nums){
        sort(nums.begin(),nums.end());
    }

    /*
        Analysis:
        TC : O(nlogn)
        SC : O(logn)
    */    

    // counting sort
    void solution2(vector<int>&nums){
        int countZero = 0, countOne = 0, countTwo = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                countZero++;
            }else if(nums[i] == 1){
                countOne++;
            }else{
                countTwo++;
            }
        }


        // Now override the actual array/ vector
        int i = 0;
        while(countZero){
            nums[i++]=0;
            countZero--;
        }

        while(countOne){
            nums[i++]=1;
            countOne--;
        }

        while(countTwo){
            nums[i++] = 2;
            countTwo--;
        }
    }

    /*
        Analysis:
        TC : O(N)
        SC : O(1)
    */    

    void sortColors(vector<int>& nums) {
        solution2(nums);
    }
};