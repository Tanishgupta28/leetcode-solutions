class Solution {
public:
int find(int a , vector<int>&par){
    if(a == par[a])return a;
    return par[a] =  find(par[a], par);
}
void uni(int a, int b, vector<int>&rank, vector<int>&par, vector<int>&ans){
    int aa = a;
    int bb = b;
    a = find(a, par);
    b = find(b, par);
    if(a==b){
        ans = {aa,bb};
        return;
    }
    else if(rank[a]>=rank[b]){
        par[b] = a;
        rank[a]+=rank[b];
    }
    else{
        par[a] = b;
        rank[b]+=rank[a];
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size();
        vector<list<int>>graph;
        vector<int>par(1001);
        vector<int>rank(1001,1);
        for(int i = 0 ; i<=1000; i++){
            par[i] = i;
        }
        for(int i = 0 ; i<n ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            uni(a,b,rank, par,  ans);
        }
        return ans;
    }
};