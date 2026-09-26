class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]){
                // age ka sorted hai 
                // to aage to increase ho rha hai to 
                // ans mid ya phir us se peeche ho skta
                lo = mid+1;
            }else{ // nums[mid]>nums[hi]
                hi = mid;
            }
        }
        return nums[lo];
    }
};