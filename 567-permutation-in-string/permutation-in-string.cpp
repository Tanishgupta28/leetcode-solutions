class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        if(n==m){
            sort(s2.begin(), s2.end());
            sort(s1.begin(), s1.end());
            if(s1==s2) return true;
            return false;
        }
        unordered_map<char, int>mp1;
        for(int i = 0 ; i< n ; i++){
            mp1[s1[i]]++;
        }
        int i = 0;
        int j = n-1;
        unordered_map<char, int>mp2;
        for(int i  = 0 ; i<n ; i++){
            mp2[s2[i]]++;
        }
        while(j<m){
            if(mp1==mp2)return true;
            else{
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);
                i++;
                j++;
                if(j==m) break;
                mp2[s2[j]]++;
            }
        }
        return false;
    }
};