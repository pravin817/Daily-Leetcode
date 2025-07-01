class Solution {
    private:

    // Function used to calculate the total number of the possible original strings that alice might have intented to type.
    int countOfPossibleStrings(const string& word) {
        int n = word.size();

        if (n == 0) {
            return 0;
        }

        int count = 1; // If the alice wrote the word correct without typing the key for too long.

        for ( int i = 1; i < n; ++i) {
            if (word[i] == word[i-1]) {
                ++count;
            }
        }

        return count;
    }
 
    /*
        Analysis:
        Time complexity  : O(n)
        Space complexity : O(1)
    */
public:
    int possibleStringCount(string word) {
        return countOfPossibleStrings(word);
    }
};