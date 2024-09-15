class Solution {
public:

    int solution1(string s)
    {
        vector<int>vowelsCount(5,0);  // a,e,i,o,u
        map<string,int>mp;            // String (state -> index)
        string currentState = "";
        int length = s.size();
        int result = 0;

        // Initial state
        mp["00000"] = -1;

        for(int i = 0; i < length ; ++i)
        {
            
            if(s[i] == 'a')
            {
                 vowelsCount[0] = (vowelsCount[0] + 1) %2;             
            }
            else if(s[i] == 'e')
            {
                    vowelsCount[1] = (vowelsCount[1] + 1) %2;
            }
            else if(s[i] == 'i')
            {
                    vowelsCount[2] = (vowelsCount[2] + 1) %2;
            }
            else if(s[i] == 'o')
            {
                    vowelsCount[3] = (vowelsCount[3] + 1) %2;
            }
            else if(s[i] == 'u')
            {
                    vowelsCount[4] = (vowelsCount[4] + 1) %2;
            }

            // form the current state
            currentState = "";
            for(int j = 0;j <5;++j)
            {
                currentState += to_string(vowelsCount[j]);
            }

            // Now find in the map
            if(mp.find(currentState)!=mp.end())
            {
                result = max(result, i - mp[currentState]);
            }
            else
            {
                mp[currentState] = i;
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */    

    int findTheLongestSubstring(string s) {
        return solution1(s);
    }
};