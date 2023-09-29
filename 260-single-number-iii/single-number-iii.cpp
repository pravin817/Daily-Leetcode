#define ll long long int

class Solution {
public:

    vector<int>solution1(vector<int>&nums){
        vector<int>ans;
        unordered_map<int,int>mp;

        for(auto n:nums){
            mp[n]++;
        }

        for(auto m:mp){
            if(m.second == 1){
                ans.push_back(m.first);
            }
        }

        return ans;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(n)
    */

    // as metioned in the problem statement don't take the extra space the above solution takes the extra space that we need to minimize for that we can use the XOR Operator.

    // This pproblem can be solved with the help of the following easy steps

    // 1) Take the xor of all the elements form the array 
    // 2) Find the right most set bit 
    // 3) Divide the input array into the two groups one has all rightmost bit is set (from 2 )  and second group don't 
    // 4) Take the xor of the two groups separatley and return the answer.

    vector<int> solution2(vector<int>&nums){

        // 1) Take the xor of all the elements from the array

        ll xor1 = 0, res1 = 0, res2 = 0;

        for(auto n:nums){
            xor1^=n;
        }

        // 2) Find the rightmost set bit 
        ll sn = xor1 & (~(xor1-1));

        // 3) 
        for(auto n:nums){
            if((n&sn)!=0){
                res1^=n;
            }else{
                res2^=n;
            }
        }

        return {(int) res1, (int)res2};
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */

    vector<int> singleNumber(vector<int>& nums) {
        return solution2(nums);
    }
};