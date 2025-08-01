class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);

        for(int i = 0;i<numRows;i++){
            ans[i] = vector<int>(i+1,1);

            for(int j = 1;j<i;j++){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans;
    }
};

/*
    This is the DP Approach
    Analysis:
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/    