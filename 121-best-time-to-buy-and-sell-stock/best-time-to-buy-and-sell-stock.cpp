class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = INT_MIN;
        int n = prices.size();
        for(int i = 0 ; i<n ; i++){
            int val = prices[i];
            minPrice = min(minPrice, val);
            int profit = val-minPrice;
            ans = max(ans, profit);
        }
        return ans;
    }
};