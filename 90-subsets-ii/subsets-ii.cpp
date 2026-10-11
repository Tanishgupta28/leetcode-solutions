class Solution {
public:
void helper(vector<int>& nums, vector<int>&temp, vector<vector<int>>&ans, int idx){
    ans.push_back(temp);
    for(int i = idx ; i<nums.size(); i++){
        if(i>idx && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        helper(nums,temp,ans,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        helper(nums,temp,ans,idx);
        return ans;
    }
};