class Solution {
public:


    /**
    * Function that counts the number of strings in the given vector `words` that contain `pref` as a prefix.
    * @param words, A vector of strings where each string consists of lowercase English letters.
    * @param pref, A string representing the prefix to check
    * @return int The number of strings in `words` that have `pref` as a prefix.
    */
    
    int solution1(const std::vector<std::string>& words, const std::string pref){
        int count = 0;

        for(std::string word : words){
            // find the string position
            size_t position = word.find(pref);

            // If the prefix is at index = 0 then it is prefix count it
            if(position != std::string::npos && position == 0){
                ++count;
            }
        }

        return count;
    }

    /*
        Analysis:
        Time Complexity  : O(n*m) , Where n is the number of the words in the array/vector and m is the average length of the string in the vector
        Space Complexity : O(1)
    */

    int prefixCount(vector<string>& words, string pref) {
        return solution1(words, pref);
    }
};