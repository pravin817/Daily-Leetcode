class Solution {
    private:
        bool checkEqual(vector<int>v1,vector<int>v2){
            for(int i = 0;i<26;i++){
                if(v1[i]!=v2[i]){
                    return 0;
                }
            }
            return 1;
        }

public:
    bool checkInclusion(string s1, string s2) {
        
        // Store the count of the character in s1 in vector count
        vector<int>count1(26,0);

         for(auto i:s1){
             count1[i-'a']++;
         }

        //  travese in s2 of window size of s1.length() 
        int i = 0;
        int windowSize = s1.length();

        // Second substring from s2
        vector<int>count2(26,0);

        // check in first window
        while(i<windowSize && i<s2.length()){
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }

        // check for the same 
        if(checkEqual(count1, count2)){
            return 1;
        }

        // check in the remaing window

        while(i<s2.length()){
            // Add character
            char addChar = s2[i];
            int index = addChar-'a';
            count2[index]++;

            // remove charcter
            char removeChar = s2[i-windowSize];
            index = removeChar - 'a';
            count2[index]--;

            i++;

            //check for the window 
            if(checkEqual(count1, count2)){
                return 1;
            }
        }

        return 0;
    }
};

/*  
    Analysis:
    Time Complexity : O(m+n)
    Space Complexity : O(1)
*/    