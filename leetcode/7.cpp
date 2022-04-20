class Solution {
public:
    int reverse(int x) {
        int pos=1;
        if(x== 1<<31) return 0;
        if(x<0){
            pos=-1;
            x*=-1;
        }
        int result=0;

        while(x!=0){
            if(result > ((1 << 30)-1)*2/10) return 0;
            result*=10;
            int dig=x%10;
            result+=dig;
            x/=10;
        }
        return result*pos;
    }
};

int reverse(int x) {
       int rev = 0;
       while (x){
           int digit = x % 10;
           x /= 10;
           if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) return 0;
           rev = rev * 10 + digit;
       }
       return rev;
   }