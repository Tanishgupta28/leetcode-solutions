class Solution {
public:
void helper(int i, int j, int sum, vector<string>&ans, string temp, int n){
    if(i>= n && j>=n){
        if(sum == 0){
            ans.push_back(temp);
        }
        return;
    }
    if(i<n){
        // temp+='(';
        helper(i+1, j , sum+1, ans, temp+'(', n);
        // temp.pop_back();
    }
    if(j<n && sum>0){
        // temp+=')';
        helper(i, j+1 , sum-1, ans, temp+')', n);
        // temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        int sum = 0;
        vector<string>ans;
        int i = 0;
        int j = 0;
        string temp;
        helper(i, j, sum, ans, temp, n);
        return ans;
    }
};