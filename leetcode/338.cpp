class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        bool condition=true;
        
        int exp=2;
        int i=1;
        if(n==0) return result;
        
        while(condition){
            // if()
            if(i==n) condition=false;
            if(i==exp) exp*=2;
            
            result[i]=1+result[i-exp/2];
            i++;
        }
        return result;
    }
};