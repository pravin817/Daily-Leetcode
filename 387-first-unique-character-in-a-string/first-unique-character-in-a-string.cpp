class Solution {
public:
    int firstUniqChar(string s) {
        int HashMap[26] = {0};

        for(int i = 0;i<s.length();i++){
            HashMap[s[i]-'a']++;
        }

        // Now traverse the string and check it count
        for(int i = 0;i<s.length();i++){
            if(HashMap[s[i]-'a'] == 1){
                return i;
            }
        }

        return -1;
    }
};

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    