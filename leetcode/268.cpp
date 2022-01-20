class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz=nums.size();
        bool ind=false;
        for(int i=0;i<sz;i++){    
            if(abs(nums[i])==sz) continue;
            else if(nums[abs(nums[i])]==0) ind=true;
            else nums[abs(nums[i])]*=-1;
        }
        for(int i=0;i<sz;i++){    
            if(nums[i]>0 || (nums[i]==0 && !ind)) {
                return i;
            }
        }
        return sz;
    }
};