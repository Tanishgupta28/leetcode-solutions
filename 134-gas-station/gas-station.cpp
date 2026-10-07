class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i<n){
            int idx = i;
            int balance = gas[idx]-cost[idx];
            while(balance>=0){
                idx++;
                if(idx%n == i) return i;
                balance+=gas[idx%n];
                balance-=cost[idx%n];
            }
            if (balance<0) i = idx+1;
        }
        return -1;
    }
};