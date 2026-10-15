class Solution {
public:
    void pacificEval(vector<vector<int>>& heights, queue<pair<int, int>> &q, vector<vector<int>>& visited) {
        while (!q.empty()) {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            int val = heights[i][j];
            int row = heights.size();
            int col = heights[0].size();
            q.pop();
            if (i > 0 && visited[i - 1][j] != 1 && heights[i - 1][j] >= val) {
                visited[i - 1][j] += 1;
                q.push({i - 1, j});
            }
            if (j > 0 && visited[i][j - 1] != 1 && heights[i][j - 1] >= val) {
                visited[i][j - 1] += 1;
                q.push({i, j - 1});
            }
            if (i < row - 1 && visited[i + 1][j] != 1 && heights[i + 1][j] >= val) {
                visited[i + 1][j] += 1;
                q.push({i + 1, j});
            }
            if (j < col - 1 && visited[i][j + 1] != 1 && heights[i][j + 1] >= val) {
                visited[i][j + 1] += 1;
                q.push({i, j + 1});
            }
        }
    }

    void atlanticEval(vector<vector<int>>& heights, queue<pair<int, int>> &q, vector<vector<int>>& visited) {
        while (!q.empty()) {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            int val = heights[i][j];
            int row = heights.size();
            int col = heights[0].size();
            q.pop();
            if (i > 0 && visited[i - 1][j] < 2  && heights[i - 1][j] >= val) {
                visited[i - 1][j] += 2;
                q.push({i - 1, j});
            }
            if (j > 0 && visited[i][j - 1] < 2 && heights[i][j - 1] >= val) {
                visited[i][j - 1] += 2;
                q.push({i, j - 1});
            }
            if (i < row - 1 && visited[i + 1][j] < 2  && heights[i + 1][j] >= val) {
                visited[i + 1][j] += 2;
                q.push({i + 1, j});
            }
            if (j < col - 1 && visited[i][j + 1] < 2 && heights[i][j + 1] >= val) {
                visited[i][j + 1] += 2;
                q.push({i, j + 1});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            q.push({i, 0});
            visited[i][0] += 1;
        }
        for (int i = 1; i < col; i++) {
            q.push({0, i});
            visited[0][i] += 1;
        }
        pacificEval(heights, q, visited);
        for (int i = 0; i < row; i++) {
            q.push({i, col - 1});
            visited[i][col - 1] += 2;
        }
        for (int i = 0; i < col-1; i++) {
            q.push({row - 1, i});
            visited[row - 1][i] += 2;
        }
        atlanticEval(heights, q, visited);
        for(int i = 0; i<row; i++){
            for(int j = 0 ; j<col; j++){
                if(visited[i][j]==3) ans.push_back({i,j});
            }
        }
        return ans;
    }
};