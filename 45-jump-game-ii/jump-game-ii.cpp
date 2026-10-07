class Solution {
public:
int helper(vector<int>& nums, int idx, int n, vector<int>&dp){
    int val = nums[idx]+idx;
    if(val>=n-1) return 1;
    int ans = 1e8;
    if(dp[idx]!=-1) return dp[idx];
    for(int i = idx+1 ; i<=val ; i++){
        ans = min(1+helper(nums,i,n,dp), ans);
    }
    return dp[idx] = ans;
}
    int jump(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        if(n==1) return 0;
        vector<int>dp(n+1, -1);
        return helper(nums, idx, n, dp);
    }
};