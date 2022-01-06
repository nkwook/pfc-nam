// 1. check what to return ... its basic....
// implementation: try to use less vars. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
            
        }
        return max;
    }
};

