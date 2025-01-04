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

        std::unordered_set<char>letters;
       
        for(int i = 0; i < str.size(); ++i){  // O(n)
            letters.insert(str[i]);
        }

        // For Each character find the start and end index
        for(char letter : letters){  // O(26)

            int startIndex = -1;
            int endIndex = -1;

            for(int i = 0; i < str.size(); ++i){  // O(n)

                // Start Index
                if(str[i] == letter) {
                    if( startIndex == -1){
                        startIndex = i;
                    }

                    // End Index
                    endIndex = i;
                } 
            }

            if(startIndex == endIndex){
                continue;
            }

            std::set<char>uniqueCharInRange;

            for(int middle = startIndex + 1; middle < endIndex; ++middle){  // O(n)
                uniqueCharInRange.insert(str[middle]);
            }

            count += uniqueCharInRange.size();
        }

        return count;
    }

    /*
        Analysis:
        Time Complexity  : O(26*N)   ===> (N)
        Space Complexity : O(26)     ===> O(1)
    */    

    // Simplified version of the above code we can precalculate the starting and the end index for the each character

    int solution3(std::string str){
        int count = 0;
        
        std::vector<std::pair<int,int>> indices(26, {-1,-1});  // O(26) ===> O(1)

        // Precomputation of the starting and the ending index
        for(int i = 0; i < str.size(); ++i){  // O(N)
            char ch = str[i];
            int index = ch - 'a';

            if(indices[index].first == -1){
                indices[index].first = i;
            }

            indices[index].second = i;
        }

        // For each character
        for(int i = 0; i < indices.size(); ++i){     // O(26)    ===> O(1)
            int startIndex = indices[i].first;
            int endIndex = indices[i].second;

            if(startIndex == endIndex){
                continue;
            }

            // Calculate the palindromic count
            unordered_set<char> uniqueChar;

            for(int middle = startIndex + 1; middle < endIndex; ++middle){  // O(N)
                uniqueChar.insert(str[middle]);
            }

            count += uniqueChar.size();
        }

        return count;
    }
    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    int countPalindromicSubsequence(string s) {
        return solution3(s);
    }
};