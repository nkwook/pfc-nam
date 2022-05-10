class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};
// very good way... do not forget!!!

class Solution {
    // important things
    /*  
        1. we should get "identity" of function. for this, backtrack function stands for
        "is it possible to make <sum> on that index?". 

        2. we can reduce nums of params like incorporating halfsum and sum

        3. backtracking order... since I used DP, we should call function that helps
        reusability first.

    
    */

public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for( int i: nums){
            totalsum+=i;
        }
        
        if(totalsum%2==1) return false;
        int halfsum=totalsum/2;
        unordered_map<int, unordered_map<int, bool>> vis;
        return backtrack(nums, halfsum, vis, 0);           
    }
    
    bool backtrack(vector<int>&nums, int sum, unordered_map<int, unordered_map<int, bool>> &vis, int idx){
        if(idx==nums.size()) return false;
        if(sum==0) return true;
        else if(sum<0) return false;
        if(vis[sum][idx]) return false;

        if(backtrack(nums, sum-nums[idx], vis, idx+1 ) ||
           backtrack(nums, sum,vis, idx+1)) return true;
        
        vis[sum][idx]=true;
        
        return false;
        
    }
    
    
};


class Solution { //TLE
public:
    static int higher(int a, int b){
            return a>b;
    }
    
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end(), higher);
        int totalsum=0;
        for( int i: nums){
            totalsum+=i;
        }
        
        if(totalsum%2==1) return false;
        int halfsum=totalsum/2;
        
        return backtrack(nums, halfsum, 0, 0);           
    }
    
    bool backtrack(vector<int>&nums, int halfsum, int sum, int idx){
        if(idx==nums.size()) return false;
        
        if(backtrack(nums,halfsum, sum, idx+1 )) return true;
        sum+=nums[idx];
        if(sum==halfsum) return true;
        else if(sum>halfsum) return false;
        
        if(backtrack(nums, halfsum, sum, idx+1) ) return true;
        return false;
        
    }
    
    
};


class Solution {
public:
    static int higher(int a, int b){
            return a>b;
    }
    
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end(), higher);
        int totalsum=0;
        for( int i: nums){
            totalsum+=i;
        }
        
        if(totalsum%2==1) return false;
        int halfsum=totalsum/2;
        unordered_map<int, unordered_map<int, bool>> vis;
          
        return backtrack(nums, halfsum, vis, 0);           
    }
    
    bool backtrack(vector<int>&nums, int sum, unordered_map<int, unordered_map<int, bool>> &vis, int idx){
        if(idx==nums.size()) return false;
        if(sum==0) return true;
        else if(sum<0) return false;
        
        if(vis[sum][idx]) return false;
        
        if(backtrack(nums, sum, vis, idx+1 ) ||
           backtrack(nums, sum-nums[idx],vis, idx+1)) return true;
        
        vis[sum][idx]=true;
        
        return false;
        
    }
    
    
};