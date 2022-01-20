class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v;
        int sz=nums.size();

        v.push_back(nums[0]);
        if(sz==1) return v[0] ;
        if(nums[0]>nums[1]) v.push_back(nums[0]);
        else v.push_back(nums[1]);

        
        for(int i=2;i<sz;i++){
            int a=v[i-2]+nums[i];
            int b=v[i-1];
            if(a>b) v.push_back(a);
            else v.push_back(b);
        }
        
        if(v[sz-1] > v[sz-2]) return v[sz-1];
        return v[sz-2];
    }
};