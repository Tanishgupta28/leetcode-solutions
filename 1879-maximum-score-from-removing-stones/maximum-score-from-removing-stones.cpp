class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        int count = 0;
        if(a>0) count++;
        if(b>0) count++;
        if(c>0) count++;
        while(count>1){
            if(a>b && a>c){
                a-=1;
                if(a==0) count--;
                if(b>=c){
                    b-=1;
                    if(b==0) count--;
                }
                else if(c>b){
                    c-=1;
                    if(c==0) count--;
                }
                ans++;
                continue;
            }
            if(b>a && b>c){
                b-=1;
                if(b==0) count--;
                if(a>=c){
                    a-=1;
                    if(a==0) count--;
                }
                else if(c>a){
                    c-=1;
                    if(c==0) count--;
                }
                ans++;
                continue;
            }
            if(c>b && c>a){
                c-=1;
                if(c==0) count--;
                if(b>=a){
                    b-=1;
                    if(b==0) count--;
                }
                else if(a>b){
                    a-=1;
                    if(a==0) count--;
                }
                ans++;
                continue;
            }
        }
        return ans;
    }
};