class Solution {
public:
void helper(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&temp, int idx){
    if(target<0) return;
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    for(int i = idx ; i<candidates.size(); i++){
        if(i>idx && candidates[i]==candidates[i-1]) continue;
        temp.push_back(candidates[i]);
        helper(candidates, target-candidates[i], ans, temp,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int idx = 0;
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ans, temp,idx);
        return ans;
    }
};

// do 
// explore 
// undo