class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int length = original.size();

        vector<vector<int>>result(m, vector<int>(n));

        if(length != m*n)
            return {};

        int k = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                result[i][j] = original[k];
                ++k;
            }
        }

        return result;
    }
};

/*
    Analysis:
    Time Compelxity : O(m*n)
    Space Complexity : O(1)
*/    