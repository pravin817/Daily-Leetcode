class Solution {
public:

    bool solution1(string s, string t){
        int m = s.length();
        int n = t.length();

        int i = 0, j = 0;

        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        if(i == m){
            return true;
        }else{
            return false;
        }
    }

    /*
        Analysis:
        Time Complexity : O(m+n)
        Space Complexity : O(1)
    */

    bool isSubsequence(string s, string t) {
        return solution1(s,t);
    }
};