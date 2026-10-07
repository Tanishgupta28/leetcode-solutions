class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        int i = 0;
        int n = nums.size();
       // if i>far then you cannot reach that far and then we need to retunr false
       while(i<n){
            if(i>far) return false;
            far = max(nums[i]+i,far);
            i++;
       }
        return true;
    }
};