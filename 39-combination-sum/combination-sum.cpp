class Solution {
public:
void helper(vector<int>& candidates, int target, int sum, vector<vector<int>>&ans, int idx, vector<int>&temp){
    if(idx==candidates.size()){
        if(sum == target){
            ans.push_back(temp);
        }
        return;
    }
    if(sum>target)return;
    helper(candidates, target, sum, ans, idx+1, temp); // move forward by doing nothing
    temp.push_back(candidates[idx]);
    helper(candidates, target, sum+candidates[idx], ans, idx, temp);// use element but do not move forward
    temp.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int idx = 0;
        int sum = 0;
        vector<int>temp;
        helper(candidates, target, sum, ans, idx, temp);
        return ans;
    }
};