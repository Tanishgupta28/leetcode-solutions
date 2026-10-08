class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n  = triplets.size();
        int x = INT_MIN;
        vector<int>temp = {x,x,x};
        int p = target[0];
        int q = target[1];
        int r = target[2];
        for(int i = 0; i<n ; i++){
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            if(a<=p && b<=q && c<=r){
                temp[0] = max(a,temp[0]);
                temp[1] = max(b,temp[1]);
                temp[2] = max(c,temp[2]);
            }
        }
        if(temp == target) return true;
        return false;
    }
};