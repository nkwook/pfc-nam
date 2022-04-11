class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        
        int idx=1;
        while(idx<=n){
            int sum=0;
            for(int i=1;i<=idx;i++){
                sum+=dp[i-1]*dp[idx-i];
            }
            
            dp[idx]=sum;
            
            idx++;
        }
        return dp[n];
    }
};