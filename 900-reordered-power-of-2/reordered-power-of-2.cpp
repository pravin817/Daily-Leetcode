class Solution {

private:
    string getSortedString(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    /*
        Analysis:
        Time Complexity  : O(dlogd)  , where d is the number of the digits in a number
        Space Complexity : O(d)
    */

public:
    bool reorderedPowerOf2(int n) {
        string s = getSortedString(n);

        for(int p = 0; p <= 30; ++p) {
            if (s == getSortedString(1 << p)) {
                return true;
            }
        }

        return false;
    }

    /*
        Analysis:
        Time Complexity   : O(29*dlogd) ==> O(dlogd), where d is the number of the digits in a number.
        Space Complexity  : O(d)
    */
};