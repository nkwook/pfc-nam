class Solution {
public:
    int mySqrt(int x) {
        return bSearch(0, x, x); // we dont have to find from 1<<16
    }
    
    int bSearch(long start, long end, int x){
        if(end-start<=1){
            if(end*end==x) return end;
            else return start;
        }
        long mid=(start+end)/2;
        
        if(mid*mid==x) return mid;
        if(mid*mid<x) return bSearch(mid, end, x);
        else return bSearch(start, mid, x);
        
        return -1;
    }
};