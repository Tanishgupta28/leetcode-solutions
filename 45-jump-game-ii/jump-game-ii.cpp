class Solution {
public:
    int jump(vector<int>& nums) {
        int i  = 0;
        int n = nums.size();
        if(n==1) return 0;
        int count = 0;
        while(i<n){
            int m = nums[i]+i;
            count++;
            if(m>=n-1) return count;
            int val = 0;
            for(int j = i+1; j<=m; j++){
                if(val < j+nums[j]){
                    i = j;
                    val = nums[j]+j;
                }
            }
        }
        return count;
    }
};