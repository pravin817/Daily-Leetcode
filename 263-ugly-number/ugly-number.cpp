class Solution {
public:
    bool isUgly(int n) {

        // The negative numbers are not the ugly numbers
        if(n <= 0){
            return false;
        }

        // Divide the number by 2,3,5 util it division is not possible
        while(n % 2 == 0)   n = n / 2;
        while(n % 3 == 0)   n = n / 3;
        while(n % 5 == 0)   n = n / 5;

        return n == 1;
    }


    /*
        Analysis:
        Time Complexity : O(logN)
        Space Complexity : O(1)
    */    
};