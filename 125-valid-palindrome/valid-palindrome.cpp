class Solution {
public:
// first check then compare  
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            char ch1 = s[i];
            char ch2 = s[j];
            ch1 = tolower(s[i]);
            ch2 = tolower(s[j]);
            bool flag1 = false;
            bool flag2 = false;
            if ((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= '0' && ch1 <= '9')){
                flag1 = true;
            }
            if ((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= '0' && ch2 <= '9')){
                flag2 = true;
            }
            if (flag1 && flag2){
                if (ch1 != ch2) return false;
                i++;
                j--;
                continue;
            }
            if(!flag1){
                i++;
            }
            if(!flag2){
                j--;
            }
        }
        return true;
    }
};