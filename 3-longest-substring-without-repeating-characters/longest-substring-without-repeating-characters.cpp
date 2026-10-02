class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans  = 0;
        int n = s.size();
        unordered_set<char>st;
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