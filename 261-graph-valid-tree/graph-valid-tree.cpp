class Solution {
public:
    bool check(vector<bool>&visited, vector<list<int>>&graph, int curr, int par){
        visited[curr] = true;
        for(int ele: graph[curr]){
            if(visited[ele]){
                if(ele!=par)return false;
                else continue;
            }
            else{
                if(!check(visited, graph, ele, curr)) return false;
            }
        }
        return true;
    } 
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<list<int>>graph(n);
        for(int i = 0 ; i<m ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool>visited(n,false);
        if(!check(visited, graph, 0, -1)) return false; 
        // checks if all nodes are connected and there is no cycle
        for(int i = 0 ; i<n ; i++){
            if(!visited[i])return false;
        }
        return true;
    }
};

// TWO CONDITION OF VALID TREE
// 1) all nodes shoud be connected
// 2) there should be no cycle
