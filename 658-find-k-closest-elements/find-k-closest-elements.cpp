class Solution {
public:
typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi>pq;
        vector<int>ans;
        int n = arr.size();
        for(int i = 0 ; i<n ; i++){
            int dist = abs(x-arr[i]);
            pq.push({dist,arr[i]});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};