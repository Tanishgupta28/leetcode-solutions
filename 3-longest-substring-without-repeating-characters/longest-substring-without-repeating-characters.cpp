class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans  = INT_MIN;
        int n = s.size();
        if(n==0)return 0;
        unordered_set<char>st;
        int count = 0;
        while(j<n){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            ans = max((int)st.size(),ans);
            j++;
        }
        return ans;
    }
};