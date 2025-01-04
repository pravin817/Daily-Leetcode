class Solution {
public:

    // Brute Force solution : By checking for the each subsequence of the length 3
    int countPalindromicSubsequenceBruteForce(std::string str){
        std::set<std::string> s;

        int n = str.size();

        for(int i = 0; i < n - 2; ++i){
            for(int j = i+1; j < n - 1; ++j){
                for(int k = j+1; k < n ; ++k){
                    if(str[i] == str[k]){
                        std::string newPalindromicSubsequence = std::to_string(str[i]) + std::to_string(str[j]) + std::to_string(str[k]);
                        s.insert(newPalindromicSubsequence);
                    }
                }
            }
        }

        return s.size();
    }

    /*
        Analysis:
        Time Complexity : O(N^3) , Where N is the length of the string str
        Space Complexity : O(N) , Where N is the Number of the unique palindromic subsequence
    */

    int solution2(std::string str){
        int count = 0;

        std::set<char>uniqueChar;
       
        for(int i = 0; i < str.size(); ++i){  // O(n)
            uniqueChar.insert(str[i]);
        }

        // For Each character find the start and end index
        for(auto currentChar : uniqueChar){  // O(n)

            int startIndex = -1;
            int endIndex = -1;

            for(int i = 0; i < str.size(); ++i){  // O(n)

                // Start Index
                if(str[i] == currentChar && startIndex == -1){
                    startIndex = i;
                }

                // End Index
                if(str[i] == currentChar){
                    endIndex = i;
                }
            }

            if(startIndex == endIndex){
                continue;
            }

            std::set<char>uniqueCharInRange;

            for(int i = startIndex + 1; i < endIndex; ++i){  // O(n)
                uniqueCharInRange.insert(str[i]);
            }

            count += uniqueCharInRange.size();
        }

        return count;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(N)
    */    

    int countPalindromicSubsequence(string s) {
        return solution2(s);
    }
};