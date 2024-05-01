class Solution {
public:
    string reversePrefix(string word, char ch) {
        string first = "";

        int i;
        for(i = 0;i<word.length();i++){
            if(word[i] == ch){
                first +=ch;
                break;
            }else{
                first+=word[i];
            }
        }

        string second ="";

        if(i == word.length()){
            return first;
        }

        if(i != word.length()){
             second = word.substr(i+1);
        }

        reverse(first.begin(),first.end());
        return first+second;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Complexity : O(N)
*/    