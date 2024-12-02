class Solution {
public:

    bool isPrefix(const std::string source, const std::string target){
        int n = source.size();
        int m = target.size();

        if(n < m){
            return false;
        }

        int i = 0, j = 0;
        while(i < n && j < m){
            if(source[i++]!=target[j++]){
                return false;
            }
        }
        return true;
    }


    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0;
        std::string word;
        std::stringstream ss(sentence);

        while(ss >> word ){
            ++count;
            if(isPrefix(word,searchWord))
                return count;
        }

        return -1;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    
};