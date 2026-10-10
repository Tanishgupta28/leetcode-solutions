class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>&ans, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i <nums.size(); i++){
            swap(nums[idx],nums[i]); // do
            helper(nums, ans ,idx+1); // explore
            swap(nums[idx],nums[i]); // undo
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>>ans;
        helper(nums, ans ,idx);
        return ans;
    }
};