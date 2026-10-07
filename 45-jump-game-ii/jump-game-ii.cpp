class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;
        int curr = 0;
        int jump = 0;
        for(int i = 0; i<n-1 ; i++){
            far = max(far,nums[i]+i);
            if(i == curr){
                curr = far;
                jump++;
            }
        }
        return jump;
    }
};