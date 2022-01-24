class Solution {
public:
    int numDecodings(string s) {
        // 1817~
        vector<int> dp(s.length(), 0);

        int idx=0;
        char prev;
        for(char c: s){
            if(c=='0' && !(prev=='1' || prev=='2')) continue;
            
            if(c=='0'){
                if(prev=='1' || prev=='2'){
                    if(idx>1 && dp[idx-2]>0) dp[idx]=dp[idx-2];
                    else dp[idx]=1;
                }
            }else if(prev=='1' || (prev=='2' && c<'7')){
                if(idx>1 && dp[idx-2]>0){
                    dp[idx]=dp[idx-1]+dp[idx-2];
                }else dp[idx]=2;
            }else{
                if(idx>0 && dp[idx-1]>0){
                    dp[idx]=dp[idx-1];
                }else dp[idx]=1;
            }
            idx++;
            prev=c;  
        }
        return dp[s.length()-1];
    }
};