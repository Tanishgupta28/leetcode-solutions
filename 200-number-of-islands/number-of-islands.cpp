class Solution {
public:
    void bfs(vector<vector<char>>& grid, queue<pair<int,int>>&q){
        int row  = grid.size();
        int col = grid[0].size();
        while(!q.empty()){
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            if(i>0 && grid[i-1][j]=='1'){
                grid[i-1][j] = 'x';
                q.push({i-1,j});
            }
            if(j>0 && grid[i][j-1]=='1'){
                grid[i][j-1] = 'x';
                q.push({i,j-1});
            }
            if(j<col-1 && grid[i][j+1]=='1'){
                grid[i][j+1] = 'x';
                q.push({i,j+1});
            }
            if(i<row-1 && grid[i+1][j]=='1'){
                grid[i+1][j] = 'x';
                q.push({i+1,j});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        queue<pair<int,int>>q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0 ; j<col; j++){
                if(grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    grid[i][j] = 'x';
                    bfs(grid,q);
                }
            }
        }
        return count;
    }
};