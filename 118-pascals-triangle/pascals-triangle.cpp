class Solution {
public:

    // The function is used to build the pascal triangle
    std::vector<std::vector<int>> buildPascalTriangle(int numRows) {

        if (numRows == 0) {
            return {};
        }

        std::vector<std::vector<int>> result(numRows);

        for(int i = 0; i < numRows; ++i) {
            result[i] = std::vector<int>(i+1,1);

            for(int j = 1; j < i; ++j) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(n^2),
                                Since the total number of the elements in the pascal triangle are as follows.

                                1+2+3+4+5+.....+n = n(n+1) / 2 
                                                  = O(n^2)
        Space Complexity : O(n^2), 
                                It is used to store the pascal triangle elements
    */

    vector<vector<int>> generate(int numRows) {
        return buildPascalTriangle(numRows); 
    }
};