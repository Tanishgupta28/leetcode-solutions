class Solution:
    def isPalindrome(self, s: str) -> bool:
        # modification 
        n = len(s)
        helper = ""
        for i in range(n):
            if(s[i].isalnum()):
                helper+=s[i].upper()
        
        m = len(helper)
        i = 0
        j = m-1
        while i<=j:
            if helper[i]!=helper[j] :
                return False
            i+=1
            j-=1
        return True