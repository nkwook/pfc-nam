class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        
        if(amount==0) return 0;
        
        for(int i=0;i<amount;i++){
            if(i!=0 && dp[i]==0) continue;
            for(int c: coins){
                if(c >10000) continue;
                if(i+c <= amount && (dp[i+c]==0 || dp[i+c] >dp[i]+1))
                    dp[i+c]=dp[i]+1;
            }
        }
        if(dp[amount]==0) return -1;
        return dp[amount];
    }
};

class Solution {

    // initialize to max, using conditions to subtract from i
    // more clean...
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};