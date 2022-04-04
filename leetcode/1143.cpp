class Solution { //1 based index => much more concise!!
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        int result=0;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
                // if(val>result) result=val; 
            }
        }
        return dp[l1][l2];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        int result=0;
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                
                int val1=0;
                int val2=0;
                int val3=0;

                if(i>0) val2=dp[i-1][j];
                if(j>0) val3=dp[i][j-1];
                if(i>0 && j>0) val1=dp[i-1][j-1];
                if(text1[i]==text2[j]) val1++;
                val1=max(val1, max(val2, val3));
                dp[i][j]=val1;
                // if(val>result) result=val; 
            }
        }
        return dp[l1-1][l2-1];
    }
};