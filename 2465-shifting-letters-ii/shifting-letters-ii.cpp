class Solution {
public:

    // Brute Force Solution
    std::string solution1(std::string &str, std::vector<std::vector<int>>&shifts){
        int n = shifts.size();

        for(int i = 0; i < n; ++i){
            int startIndex = shifts[i][0];
            int endIndex   = shifts[i][1];
            int direction  = shifts[i][2];

            for(int shiftLetterAt = startIndex; shiftLetterAt <= endIndex; ++ shiftLetterAt){

                if(direction){
                    str[shiftLetterAt] = ((str[shiftLetterAt] - 'a' + 1 )  % 26 ) + 'a';
                } else {
                     str[shiftLetterAt] = ((str[shiftLetterAt] - 'a' - 1 + 26) % 26) + 'a';
                }
            }
        }
        return str;
    }

    /*
        Analysis:
        Time Complexity  : O(n*m) , Where n is the Number of the shift operation and m is the length of the string
        Space Complexity : O(1)
    */

    // Note : The above solution gives TLE we need to optimised it

    // Solution using the difference array
    std::string solution2(std::string &str, std::vector<std::vector<int>>& shifts){

        int n = str.size();
        std::vector<int>diffArray(n, 0);
        int currentUpdate = 0;

        for(const auto& shift : shifts){  // O(Q)
            int startIndex = shift[0];
            int endIndex   = shift[1];
            int direction  = shift[2];

           if(direction == 1){  // Forward direction
                diffArray[startIndex] += 1;

                if(endIndex + 1 < n){
                    diffArray[endIndex + 1] -= 1;
                }
           } else {
                 diffArray[startIndex] -= 1;

                if(endIndex + 1 < n){
                    diffArray[endIndex + 1] += 1;
                }
           }
        }

        // Now update the string
        for(int i = 0; i < str.size(); ++i){  // O(N)
            currentUpdate += diffArray[i];

            int shift = currentUpdate % 26;

            if(shift < 0)
                shift += 26;

            str[i] = ((str[i] - 'a' + shift ) % 26 ) + 'a';
        }

        return str;
    }

    /*
        Analysis:
        Time Complexity : O(n+m) , Where n is the length of the string and m is the length of the queries i.e shifts
        Space Complexity : O(n), n is the length of the string
    */

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        return solution2(s, shifts);
    }
};