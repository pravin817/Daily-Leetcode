class Solution {
public:
    int minimumArea(vector<vector<int>>& grid, int st_y, int en_y, int st_x, int en_x){
        int a, b, c, d;
        a = b = INT_MAX;
        c = d = 0;
        /*
            a
        ---------
      b |       | d
        |       |
        ---------
           c
        */
        for(int i = st_x; i <= en_x; i++){
            for(int j = st_y; j <= en_y; j++){
                if(grid[i][j] == 1){
                    a = min(a, i);
                    b = min(b, j);
                    c = max(c, i);
                    d = max(d, j);
                }
            }
        }
        if(a == INT_MAX || b == INT_MAX || c == INT_MAX || d == INT_MAX) return 0;
        return (c-a+1)*(d-b+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = INT_MAX;
        /*
        -----------
        |    1    |
        -----------
        | 2  | 3  |
        -----------
        */
        for(int i = 0; i < n-1; i++){
            int one = minimumArea(grid, 0, m-1, 0, i);
            if(one == 0) continue;
            for(int j = 0; j < m-1; j++){
                int two = minimumArea(grid, 0, j, i+1, n-1);
                int three = minimumArea(grid, j+1, m-1, i+1, n-1);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }

        /*
        -----------
        | 2  | 3  |
        -----------
        |    1    |
        -----------
        */
        for(int i = 0; i < n-1; i++){
            int one = minimumArea(grid, 0, m-1, i+1, n-1);
            if(one == 0) continue;
            for(int j = 0; j < m-1; j++){
                int two = minimumArea(grid, 0, j, 0, i);
                int three = minimumArea(grid, j+1, m-1, 0, i);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }

        /*
        -----------
        |    | 2  |
        | 1  ------
        |    | 3  |
        -----------
        */
        for(int i = 0; i < m-1; i++){
            int one = minimumArea(grid, 0, i, 0, n-1);
            if(one == 0) continue;
            for(int j = 0; j < n-1; j++){
                int two = minimumArea(grid, i+1, m-1, 0, j);
                int three = minimumArea(grid, i+1, m-1, j+1, n-1);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }

        /*
        -----------
        | 2  |    |
        -----  1  |
        | 3  |    |
        -----------
        */
        for(int i = 0; i < m-1; i++){
            int one = minimumArea(grid, i+1, m-1, 0, n-1);
            if(one == 0) continue;
            for(int j = 0; j < n-1; j++){
                int two = minimumArea(grid, 0, i, 0, j);
                int three = minimumArea(grid, 0, i, j+1, n-1);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }

        /*
        -----------
        |    1    |
        -----------
        |    2    |
        -----------
        |    3    |
        -----------
        */
        for(int i = 0; i < n-2; i++){
            int one = minimumArea(grid, 0, m-1, 0, i);
            if(one == 0) continue;
            for(int j = i+1; j < n-1; j++){
                int two = minimumArea(grid, 0, m-1, i+1, j);
                int three = minimumArea(grid, 0, m-1, j+1, n-1);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }

        /*
        -----------------
        |    |    |     |
        | 1  |  2 |  3  |
        |    |    |     |
        -----------------
        */
        for(int i = 0; i < m-2; i++){
            int one = minimumArea(grid, 0, i, 0, n-1);
            if(one == 0) continue;
            for(int j = i+1; j < m-1; j++){
                int two = minimumArea(grid, i+1, j, 0, n-1);
                int three = minimumArea(grid, j+1, m-1, 0, n-1);
                if(two == 0 || three == 0) continue;
                ans = min(ans, one+two+three);
            }
        }
        return ans;
    }

    // CP
};