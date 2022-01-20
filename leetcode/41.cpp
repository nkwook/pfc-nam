class Solution { // SC(N)
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz=nums.size();
        vector<int> vis(sz, 0);
        for(auto n:nums){
            if(n>0 && n<=sz) vis[n-1]=1;
        }
        for(int i=0;i<sz;i++){
            if(vis[i]==0) return i+1;
        }
        return sz+1;
    }
};

class Solution { //SC(1)
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int dummy=n+1;
        
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nums[i]=dummy;
            }        
        }
        for( int i=0;i<n;i++){
            if(abs(nums[i])>=dummy) continue;
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=-1;
            }
        }
            
        for(int i=0;i<n;i++){
            // cout << nums[i];
            if(nums[i]>0) return i+1;
        }
        return n+1;
        
        
    }
};