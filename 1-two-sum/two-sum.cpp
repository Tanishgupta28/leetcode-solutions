// takes o(nlog n).
// not most optimal in terms of time complexity .
class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pi>helper;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            helper.push_back({nums[i],i});
        }
        sort(helper.begin(), helper.end());
        int i = 0 ; 
        int j = helper.size()-1;
        while(i<j){
            int sum = helper[i].first+helper[j].first;
            if(sum == target )return{helper[i].second,helper[j].second};
            else if(sum<target)i++;
            else j--;
        }
        return{};
    }
};