class Solution {
public:

    void DFS(vector<vector<char>> &grid, int i, int j){
        // check the boundry conditions
        if(i < 0 ||i >= grid.size() || j < 0 || j>= grid[0].size()){
            return;
        }   

        // check if already visited 
        if(grid[i][j] == '0' || grid[i][j] == '$'){
            return;
        }

        // Mark the current as visited
        grid[i][j] = '$';

        // DO DFS in all 4 directions
        DFS(grid, i+1,j);
        DFS(grid, i-1,j);
        DFS(grid, i,j+1);
        DFS(grid, i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int islands = 0;

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == '1'){
                    DFS(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};