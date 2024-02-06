class Solution {
    public boolean isPalindrome(int x) {
        // edge case ---> negative numbers are not palindrome at all
        if(x<0){
            return false;
        }

        int ori = x;
        int rev = 0;
        while(x>0){
            int lastDigit = x % 10;
            rev = (rev*10)+lastDigit;
            x = x / 10;
        }

        return ori == rev;
    }
}

/*
    Analysis:
    Time Complexity : O(logn)
    Space Complexity : O(1)
*/    