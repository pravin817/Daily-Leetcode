class Solution {
public:

    int n, m;
    vector<vector<int>>ans;

    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void DFS(vector<vector<int>>&land, int i, int j, int &r2, int &c2){

        // mark as visited
        land[i][j] = 0;

        // find the right column idx
        r2 = max(r2,i);
        c2 = max(c2,j);

        // Now traverse
        for(auto &dir : directions){
            int i_ = i+dir[0];
            int j_ = j+dir[1];

            // check for the valid index
            if(i_ >= 0 && i_ < m && j_ >= 0  && j_ < n && land[i_][j_] == 1){
                DFS(land,i_,j_,r2,c2);
            }
        }
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Space Complexity : O(1)  --> By ignoring the stack space
    */  

    void BFS(vector<vector<int>>&land, int i, int j, int &r2, int &c2){
        queue<pair<int,int>>que;
        que.push({i,j});

        while(!que.empty()){
            pair<int,int>p = que.front();
            que.pop();

            // update the r2 and c2
            r2 = max(r2, p.first);
            c2 = max(c2, p.second);

            for(auto &dir:directions){
                int i_ = p.first+dir[0];
                int j_ = p.second+dir[1];

                // check the bound condition
                if(i_ >= 0 && i_ <m && j_ >=0 && j_ <n && land[i_][j_] == 1){
                    // mark as visited
                    land[i_][j_] =0;

                    que.push({i_,j_});
                }
            }
        }
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Space Complexity : O(n*m)
    */  

    vector<vector<int>>solution3(vector<vector<int>> &land){
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>>result;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){

                if(land[i][j] == 0){
                    continue;
                }

                // find the right most column of the current group
                int c1 = j;
                while(c1<n && land[i][c1] == 1){
                    c1++;
                }

                // find the right most row of the current group
                int r1 = i;
                while(r1<m && land[r1][j] == 1){
                    r1++;
                }

                c1 = c1 == 0 ? c1 : c1-1;
                r1 = r1 == 0 ? r1 : r1-1;

                result.push_back({i,j,r1,c1});
                // mark as visited
                for(int k = i;k<=r1;k++){
                    for(int l = j;l<=c1;l++){
                        land[k][l] = 0;
                    }
                }
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Space Complexity : O(1)
    */    

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // m = land.size();
        // n = land[0].size();

        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //         if(land[i][j] == 1){
        //             int r1 = i;
        //             int c1 = j;
        //             int r2 = -1;
        //             int c2 = -1;

        //             BFS(land,i,j,r2,c2);

        //             ans.push_back({r1,c1,r2,c2});    
        //          }
        //     }
        // }

        // return ans;

        return solution3(land);
    }
};