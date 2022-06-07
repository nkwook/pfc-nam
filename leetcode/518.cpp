class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        int val=0;
        while(val<=amount){
            dp[val]++;
            val+=coins[0];
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<amount;j++){
                if(!dp[j] || j+coins[i] >amount) continue;
                dp[j+coins[i]]+=dp[j];
            }
        
        }
        return dp[amount];
    }
};


class Solution { //TLE
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    
    int change(int amount, vector<int>& coins) {
      int result=0;
      sort(coins.begin(), coins.end(), cmp);
      rec(amount, coins, 0, result);
      return result;
    }

    void rec(int amount, vector<int>&coins, int cur, int &result){
      if(amount==0){
        result++;
        return;
      }
      if(amount<0 || cur>=coins.size()) return;
      
      while(amount>=0){
        rec(amount, coins, cur+1, result);
        amount-=coins[cur];
      }
      
      return;
    }
};