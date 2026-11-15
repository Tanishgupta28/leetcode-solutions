class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        mp = {}
        n = len(s)
        for i in range(n):
            mp[s[i]]=mp.get(s[i],0)+1
            mp[t[i]] = mp.get(t[i],0)-1
        
        for value in mp.values():
            if value !=0:
                return False
        return True 