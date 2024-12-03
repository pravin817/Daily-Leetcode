class Solution {
public:

    string solution1(const std::string &s, const std::vector<int>&spaces){
        std::string result = "";
        int len = s.size();
        int n = spaces.size();

        int i = 0;
        int j = 0;

        while( i < len){
            if((j < n) && (i == spaces[j])){
                result += " ";
                result += s[i];
                ++i;
                ++j;
            }else{
                result += s[i];
                ++i;
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N)     ----> Where N is the length of the string
        Space Complexity : O(1)
    */

    string addSpaces(string s, vector<int>& spaces) {
        return solution1(s, spaces);
    }
};