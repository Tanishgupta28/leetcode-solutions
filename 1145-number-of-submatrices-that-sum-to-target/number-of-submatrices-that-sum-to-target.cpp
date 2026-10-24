class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>helper(n, vector<int>(m));
        int ans = 0;
        int currRow = 0;
        while(currRow<n){
            vector<vector<int>>helper(n, vector<int>(m));
            for(int j = 0; j<m; j++){
                int sum = 0;
                for(int i = currRow; i<n ;i++){
                    sum+=matrix[i][j];
                    helper[i][j] = sum;
                }
            }
            for(int i = currRow; i<n; i++){
                int sum = 0;
                unordered_map<int,int>mp;
                mp[0] = 1;
                for(int j = 0 ; j<m ; j++){
                    sum+=helper[i][j];
                    if(mp.count(sum-target)){
                        ans+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
            currRow++;
        }
        return ans;
    }
};