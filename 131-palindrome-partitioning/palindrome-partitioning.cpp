class Solution {
public:
bool PalindromeCheck(string&temp){
    int n = temp.size();
    int i = 0;
    int j = n-1;
    while(i<=j){
        if(temp[i]!=temp[j]) return false;
        i++;
        j--;
    }
    return true;
}
    void helper(vector<vector<string>>&ans, vector<string>&help, int idx, string s){
        if(idx>=s.size()){
            ans.push_back(help);
            return;
        }
        string temp = "";
        for(int i = idx; i<s.size(); i++){
            temp.push_back(s[i]);
            if(PalindromeCheck(temp)){
                help.push_back(temp);
                helper(ans, help, i+1, s);
                help.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int idx = 0;
        vector<vector<string>>ans;
        vector<string>help;
        helper(ans, help, idx, s);
        return ans;
    }
};