class Solution {
public:

    // simple traverse the string and reverse the words from the string
    string solution1(string &s){
        int n = s.length();

        for(int i = 0;i<n;i++){
            if(s[i]!=' '){
                int j = i;

                // move to the end of the word
                while(j<n && s[j]!=' '){
                    j++;
                }

                // Now reverse the word from the string
                reverse(begin(s)+i, begin(s)+j);
                
                // Now move the i to the j
                i = j;
            }
        }
        return s;
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(1)
    */

    // Solution by using the tokenising
    string solution2(string &s){

        stringstream ss(s);

        // token (word from the string)
        string token = "";

        // string to store the result
        string result = "";

        // get each token from the string and reverse it.

        while(ss>>token){

            // reverse the token
            reverse(token.begin(),token.end());

            // add the reverse token to the result.
            result +=token+" ";
        }

        // one extra space is added at the end of the string remove it.
        return result.substr(0,result.length()-1);
    }

    /*
        Analysis:
        Time Complexity : O(n)
        Space Complexity : O(n)
    */

    string reverseWords(string s) {
        return solution2(s);
    }
};