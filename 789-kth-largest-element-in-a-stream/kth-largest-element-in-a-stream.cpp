class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>>pq;
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(pq.size()<k)pq.push(nums[i]);
            else if(pq.size()==k){
                int top = pq.top();
                if(nums[i]>=top){
                    pq.pop();
                    pq.push(nums[i]);
                }
                else continue;
            }
        }  
    }
    
    int add(int val) {
        if(pq.size()<k){
            pq.push(val);
        }
        else if(pq.size()==k){
            if(val>=pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
