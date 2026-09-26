class Solution {
public:
    long long find(int amount, vector<int>& piles){
        int n = piles.size();
        long long ans = 0;
        for(int i = 0 ; i< n ; i++){
            if(piles[i]%amount==0) ans+=(piles[i]/amount);
            else ans+=(piles[i]/amount)+1;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxquant = * max_element(piles.begin(), piles.end());
        int lo = 1;
        int hi = maxquant;
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(find(mid, piles)>h){
                lo = mid+1;
            }else{
                ans = min(ans,mid);
                hi = mid-1;
            }
        }
        return ans;
    }
};