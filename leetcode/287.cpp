class Solution { // SP(N)
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n, 0);
        for(auto x: nums){
            if(v[x-1]==1){
                return x;
            }
            v[x-1]++;
        }
        return 0;
    }
};

class Solution { //SP(1)
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
       
            nums[abs(nums[i])-1]*=-1;
        }
        return 0;
    }
};