class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        int mex = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++){
            int curr = nums[i]%val;
            if(curr<0) curr = (curr+val)%val;
            mp[curr]++;
        }
        while(mp.find(mex%val)!=mp.end()){
            mp[mex%val]--;
            if(mp[mex%val]==0) mp.erase(mex%val);
            mex++;
        }
        return mex;
    }
};