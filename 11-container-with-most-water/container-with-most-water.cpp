// two pointer solution (similar to binary search)
// if we want to chnege our current state and wnat to improve then which pointer should be moved
// one having smaller height (becasue moving pointer with larger height may not improve the situation)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN;
        int i = 0;
        int j = n-1;
        while(i<=j){
            int dist = j-i;
            int hiet = min(height[i], height[j]);
            int val = hiet*dist;
            ans = max(ans, val);
            if(height[i]<= height[j]){
                i++;
            }else j--;
        }
        return ans;
    }
};