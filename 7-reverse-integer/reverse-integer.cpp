class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while(x){

            // Take the lastDigit
            int lastDigit = x % 10;

            // Check the underflow and overfloe
            if(ans> INT_MAX/10 || ans < INT_MIN/10){
                return 0;
            }

            // add the lastDigit to ans
            ans = ans*10 + lastDigit;

            // update the num
            x = x / 10;
        }
        return ans;
    }
};

/*
    Analysis:
    Time Complexity : O(log10(n))
    Space Complexity : O(1)
*/