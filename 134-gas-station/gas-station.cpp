class Solution {
public:
bool check(int curr, int idx, vector<int>& gas, vector<int>& cost, int n, int& idx1){
    if(idx1 == idx%n) return true;
    curr+=gas[idx%n];
    curr-=cost[idx%n];
    if(curr<0){
        idx1 = idx+1;
        return false;
    }
    return check(curr, idx+1, gas, cost, n, idx1);

}
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i  = 0;
        while(i<n){
            int curr = gas[i]-cost[i];//current balance
            if(curr>=0){
                if(check(curr, i+1, gas, cost, n, i)) return i;
                continue;
            }
            i++;
        }
        return -1;
    }
};