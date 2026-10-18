class Solution {
public:
    int find(int a, vector<int>&par){
        if(a==par[a]) return a;
        return par[a] = find(par[a], par); // path compression
    }
    void uni(int a, int b, vector<int>&rank, vector<int>&par){
        a = find(a, par);
        b = find(b, par);
        if(a==b)return;
        if(rank[a]>=rank[b]){
            rank[a]+=rank[b];
            par[b] = a;
        }else{
            rank[b]+=rank[a];
            par[a] = b;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>par(n);
        for(int i = 0 ; i<n ; i++){
            par[i] = i;
        }
        // shows initially every node is parent of itself 
        vector<int>rank(n,1); 
        // shows initial rank of veery node
        int m = edges.size();
        for(int i = 0 ; i<m ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            uni(a,b,rank,par);
        }
        for(int i = 0 ; i<n ; i++){
            find(i, par);
        }
        set<int>st;
        for(int i = 0; i<n ; i++){
            st.insert(par[i]);
        }
        return st.size();
    }
};

// we can simply do this using DFS but we will do this using  DSU for practice