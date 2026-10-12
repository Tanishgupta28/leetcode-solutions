class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>&q){
        int count = 1;
        int row = grid.size();
        int col  = grid[0].size();
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i>0 && grid[i-1][j]==1){
                grid[i-1][j] = -1;
                q.push({i-1,j});
                count++;
            }
            if(j>0 && grid[i][j-1]==1){
                grid[i][j-1] = -1;
                q.push({i,j-1});
                count++;
            }
            if(i<row-1 && grid[i+1][j]==1){
                grid[i+1][j] = -1;
                q.push({i+1,j});
                count++;
            }
            if(j<col-1 && grid[i][j+1]==1){
                grid[i][j+1] = -1;
                q.push({i,j+1});
                count++;
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area  = 0;
        int row  = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j]==1){
                   q.push({i,j});
                   grid[i][j] = -1;
                   area = max(area, bfs(grid,q));
                }
            }
        }
        return area;
    }
};