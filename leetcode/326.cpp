class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        if(n==1) return true;
        else if ((n%3)!=0) return false;
        return isPowerOfThree(n/3);
    }
};

class Solution { //pow is slower...
public:
    bool isPowerOfThree(int n) {
     return n>0 && (1162261467 %n)==0;
    }
};