class Solution {
public:
typedef pair<int,int> pp;
typedef pair<int, pp> pip;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pip, vector<pip>, greater<pip>>pq; // min heap
        int n = nums.size();
        int maxele = INT_MIN;
        for(int i = 0 ; i<n; i++){
            pq.push({nums[i][0], {i,0}});
            maxele = max(maxele, nums[i][0]);
        }
        vector<int>currrange = {pq.top().first, maxele};
        int curr = maxele - pq.top().first;
        while(!pq.empty()){
            auto cord = pq.top();
            int i = cord.second.first;
            int j = cord.second.second;
            pq.pop();
            if(j+1<nums[i].size()){
                pq.push({nums[i][j+1], {i, j+1}});
                if(maxele<nums[i][j+1])maxele = nums[i][j+1];
                int diff = maxele - pq.top().first;
                if(diff < curr || (diff == curr && pq.top().first < currrange[0])){
                    curr = diff;
                    currrange = {pq.top().first, maxele};
                }
            }
            if(j+1 == nums[i].size()) break;
        }
        return currrange;
    }
};