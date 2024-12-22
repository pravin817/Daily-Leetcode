class Solution {
public:

    std::vector<vector<int>> solution1(std::vector<std::vector<int>>&matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<int>> result(col, vector<int>(row,0));

        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
              result[i][j] = matrix[j][i];
            }
        }
        return result;
    }
    /*
        Analysis:
        Time Complexity : O(n*m)
        Space Complexity : O(n*m)
    */

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        return solution1(matrix);
    }
};