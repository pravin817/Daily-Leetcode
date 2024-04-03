class Solution {

public:
    int m, n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>&board, int i, int j,int idx, string word){
        // Base case
        if(idx == word.length()){
            return true;
        }

        // check out of bond
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == '$' || board[i][j]!=word[idx]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$'; 


        // Backtrack code
        for(auto &dir :directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            if(find(board,new_i,new_j,idx+1,word)){
                return true; 
            }
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // Traverse the board
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int idx = 0; 
                if(board[i][j] == word[idx] && find(board,i,j,idx,word) ){
                    return true;
                }
            }
        }
        return false;
    }
};