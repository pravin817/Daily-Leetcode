class Solution {
public:

    int solution(const std::string &s)
    {
       int n = s.size();

       int count = 0;

       for(int i = 0; i < n; i+=2)
       {
        count+= (s[i] != s[i+1]);
       }

       return count;
    }
    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    

    int minChanges(string s) {
        return solution(s);
    }
};