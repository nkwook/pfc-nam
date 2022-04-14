class Solution {
public:
    int jump(vector<int>& nums) {
        int MAX=100000;
        vector<int> dp(nums.size(), MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==MAX) continue;
            for(int j=1;j<=nums[i];j++){
                if(i+j>=nums.size()) break;
                else if(i+j==nums.size()) return dp[i]+1;
                if(dp[i+j]>dp[i]+1) dp[i+j]=dp[i]+1;
                
            }
        }
        return dp[nums.size()-1];   
    }
};


class Solution { // nice bfs solution...
public:
    int jump(vector<int>& nums) {
        int start=0;
        int end=0 ;
        int maxEnd=0;
        int jumps=0;
        while(end<nums.size()-1){
            jumps++;
            cout << start << ' ' << end << '\n';
            for(int i=start; i<=end;i++){
                if(i+nums[i]>=nums.size()-1) return jumps;
                maxEnd=max(maxEnd, i+nums[i]);
            }
            start=end+1;
            end=maxEnd;
        }   
        return jumps;
        
    }
    
};