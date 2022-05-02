class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos=0;
        int idx=0;
        int temp=-1;
        
        while(nums.size()>idx){
            if(nums[idx]%2==0){
                temp=nums[pos];
                nums[pos]=nums[idx];
                nums[idx]=temp;
                pos++;
            }
            
            idx++;
        }
        return nums;
    }
};