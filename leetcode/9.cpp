class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int reverseX=0;
        
        int cnt=0;
        int c=x;
        
        while(c){
            int dig=c%10;
            if(reverseX > (INT_MAX - dig)/10){
                return false;
            }
            c/=10;
            reverseX=reverseX*10+dig;
        }
        return x==reverseX;
        
    }
};