class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n+1, -1);
        v[0]=0;
        v[1]=1;
        
        // int min;
        int temp;
        for(int i=2;i<=n;i++){
            int s=(int)sqrt(i);
            for(int j=s;j>=1;j--){
                temp=v[i-j*j]+1;
                if(v[i]==-1 || v[i] > temp){
                    v[i]=temp;
                }
            }
        }
        return v[n];
    }
};