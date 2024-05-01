class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0;i<word.length();i++){
            if(word[i] == ch){
                reverse(begin(word),begin(word)+i+1);
                break;
            }
        }

        return word;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Complexity : O(1)
*/    