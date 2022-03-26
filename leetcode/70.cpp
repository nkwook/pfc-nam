class Solution {
public:
    int climbStairs(int n) {
        int result;
        int before=2;
        int before2=1;
        int temp=before;

        if(n<=2) return n;
        int iter=n-2;
        while(iter--){
            temp=before;
            before=before+before2;
            before2=temp;
        }
        return before;
        
    }
};