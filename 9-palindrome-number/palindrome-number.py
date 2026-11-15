class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp = str(x)
        n = len(temp)
        i = 0
        j = n-1
        while i<=j:
            if temp[i]!=temp[j]:
                return False
            i+=1
            j-=1
        return True