class Solution {
public:

    int solution1(const std::string &str)
    {
        int n = str.size();

        int openingBracketCnt = 0;
        int closingBracketCnt = 0;

        for(int i = 0; i < n ; ++i)
        {
            if(str[i] == '(')
                ++openingBracketCnt;
            else if(str[i] == ')' && openingBracketCnt > 0) 
                --openingBracketCnt;
            else
                ++closingBracketCnt;    
        }

        return abs(openingBracketCnt + closingBracketCnt);
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    

    int minAddToMakeValid(string s) {
        return solution1(s);
    }
};