class Solution {
public:

    bool solution1(int n){
        // base case 
        if(n == 1){
            return true;
        }

        if(n < 0){
            return false;
        }

        for(int i = 1;i<=n/i;i++){
            if(pow(4,i) == n){
                return true;
            }
        }

        return false;
    }

    bool isPowerOfFour(int n) {
        return solution1(n);
    }
};