class Solution { // O(N^2)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       int dp[n];
        
       for(int i=0;i<n;i++){
           dp[i]=1;
       } 
        int max=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[i]>dp[j]) continue;
                if(nums[i]>nums[j]){
                    dp[i]=dp[j]+1;
                    if(max<dp[i]) max=dp[i];
                }                
            }
        }
        return max;
    }
};