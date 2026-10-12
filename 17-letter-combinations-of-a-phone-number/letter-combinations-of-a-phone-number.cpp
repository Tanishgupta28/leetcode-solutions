class Solution {
public:
void assignVal(unordered_map<int,vector<char>>&mp){
    int count = 0;
    for(int i = 2 ; i<=9 ; i++){
            if(i!=7 && i!=9){
                for(int j = 0; j<3; j++){
                    mp[i].push_back(count+'a');
                    count++;
                }
            }
            else{
                for(int j = 0; j<4; j++){
                    mp[i].push_back(count+'a');
                    count++;
                }
            }
    }
}
    void helper(vector<string>&ans, unordered_map<int,vector<char>>&mp, string& digits, string& temp, int idx){
        if(idx >= digits.size()){
            ans.push_back(temp);
            return;
        }
        vector<char>curr = mp[digits[idx]-'0'];
        for(int i = 0; i< curr.size(); i++){
            temp.push_back(curr[i]);
            helper(ans,mp,digits,temp,idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return{};
        unordered_map<int,vector<char>>mp;
        assignVal(mp);
        int idx = 0;
        vector<string>ans;
        string temp;
        helper(ans,mp,digits,temp, idx);
        return ans;
    }
};