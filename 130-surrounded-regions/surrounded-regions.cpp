class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        queue<pair<int,int>>q;
        for(int i = 0 ; i<row; i++){
            if(board[i][0] == 'O'){
                 q.push({i,0});
                 board[i][0] = 'T';
            }
            if(board[i][col-1]== 'O'){
                q.push({i,col-1});
                board[i][col-1] = 'T';
            }
        }
        for(int i = 1 ; i<col-1; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                board[0][i] = 'T';
            }
            if(board[row-1][i] == 'O'){
                q.push({row-1,i});
                board[row-1][i] = 'T';
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i>0 && board[i-1][j] =='O'){
                q.push({i-1,j});
                board[i-1][j] = 'T';
            }
            if(j>0 && board[i][j-1] =='O'){
                q.push({i,j-1});
                board[i][j-1] = 'T';
            }
            if(i<row-1 && board[i+1][j] =='O'){
                q.push({i+1,j});
                board[i+1][j] = 'T';
            }
            if(j<col-1 && board[i][j+1] =='O'){
                q.push({i,j+1});
                board[i][j+1] = 'T';
            }
        }
        for(int i = 0 ; i<row; i++){
            for(int j = 0 ; j<col; j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]=='T') board[i][j] = 'O';
            }
        }
    }
};