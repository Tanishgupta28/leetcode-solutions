class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int>mp(26,0);
        int m = tasks.size();
        for(int i = 0 ; i<m ; i++){
            mp[tasks[i]-'A']++;
            // marking down the frequency of differnet charecters
        }
        priority_queue<int>pq; //max heap
        for(int i = 0 ; i<26; i++){
            if(mp[i]>0)pq.push(mp[i]);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i = 1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq = freq-1;
                    temp.push_back(freq);
                }
            }
            int z = temp.size();
            for(int i = 0 ; i<z; i++){
                if(temp[i]!=0) pq.push(temp[i]);
            }
            if(pq.empty()) time+=z;
            else time+=n+1;
        }
        return time;
    }
};