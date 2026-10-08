class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i = 0 ; i<n ; i++){
            mp[s[i]]++;
        }
        vector<int>ans;
        int i = 0;
        while(i<n){
            unordered_set<char>st;
            st.insert(s[i]);
            int j = i;
            while(!st.empty()&&j<n){
                if(st.find(s[j])==st.end())st.insert(s[j]);
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                    st.erase(s[j]);
                }
                j++;
            }
            int val = j-i;
            ans.push_back(val);
            i = j;
        }
        return ans;
    }
};