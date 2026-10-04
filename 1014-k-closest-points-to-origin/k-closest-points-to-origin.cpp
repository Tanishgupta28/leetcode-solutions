class Solution {
public:
    typedef pair<long long,vector<int>> pi;
int partition(vector<pi>&nums, int left, int right){
    long long pivot = nums[right].first;
    int n = nums.size();
    int count = 0;
    for(int i = left ; i<=right ; i++){
        if(nums[i].first<pivot)count++;
    }
    int pivotIndex = left + count;
    swap(nums[pivotIndex], nums[right]);
    int i = left;
    int j = right;
    while(i < pivotIndex && j > pivotIndex){
        while(i < pivotIndex && nums[i].first < pivot)
            i++;
        while(j > pivotIndex && nums[j].first >= pivot)
            j--;
        if(i < pivotIndex && j > pivotIndex) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pi>helper;
        int n = points.size();
        for(int i = 0 ; i< n ; i++){
            long long x = points[i][0];
            long long y = points[i][1];
            long long val = x*x + y*y;
            helper.push_back({val,points[i]});
        }
        int left = 0 ; 
        int right = n-1;
        while(left<=right){
            int p = partition(helper,left,right);
            if(p==k-1) break;
            else if(p<k-1) left = p+1;
            else right = p-1;
        }
        vector<vector<int>>ans;
        for(int i = 0 ; i<k ; i++){
            ans.push_back(helper[i].second);
        }
        return ans;
    }   
};