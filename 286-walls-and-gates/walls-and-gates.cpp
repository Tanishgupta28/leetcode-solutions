class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<m; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int val = 1;
        while(!q.empty()){
            int count = q.size();
            while(count){
                auto curr = q.front();
                q.pop();
                count--;
                int i = curr.first;
                int j = curr.second;
                if(i>0 && rooms[i-1][j]>1e9){
                    rooms[i-1][j] = val;
                    q.push({i-1,j});
                }
                if(j>0 && rooms[i][j-1]>1e9){
                    rooms[i][j-1] = val;
                    q.push({i,j-1});
                }
                if(i<n-1 && rooms[i+1][j]>1e9){
                    rooms[i+1][j] = val;
                    q.push({i+1,j});
                }
                if(j<m-1 && rooms[i][j+1]>1e9){
                    rooms[i][j+1] = val;
                    q.push({i,j+1});
                }
            }
            val++;
        }
    }
};