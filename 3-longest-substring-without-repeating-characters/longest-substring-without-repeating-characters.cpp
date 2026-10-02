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
            while(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
                if(j>=n){
                    ans = max(ans,(int)st.size());
                    break;
                }
            }
            ans = max((int)st.size(),ans);
            while(st.find(s[j])!=st.end()){
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            j++;
        }
        return ans;
    }
};