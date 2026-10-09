class Solution {
public:
void helper(vector<int>& nums, int idx, vector<vector<int>>&ans, vector<int>&temp){
    if(idx==nums.size()){
        ans.push_back(temp);
        return;
    }
    helper(nums, idx+1, ans, temp);
    temp.push_back(nums[idx]);
    helper(nums, idx+1, ans, temp);
    temp.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       int idx = 0;
       vector<int>temp;
       helper(nums, idx, ans, temp);
       return ans;
    }
};