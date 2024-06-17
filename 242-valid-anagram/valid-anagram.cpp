class Solution {
public:

    // Brute Force - by using the sorting
    bool solution1(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;
    }

    /*  
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(1)
    */


    bool isAnagram(string s, string t) {
        return solution1(s,t);
    }
};